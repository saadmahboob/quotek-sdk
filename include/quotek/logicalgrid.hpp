/*
Quotek Strategies SDK 3.0
Copyright 2013-2016 Quotek SAS
*/

#ifndef LOGICALGRID_HPP
#define LOGICALGRID_HPP

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "utils.hpp"

#define CELL_NAND 0x01
#define CELL_NOR 0x02
#define CELL_NXOR 0x03

#define CELL_AND 0x04
#define CELL_OR 0x05
#define CELL_XOR 0x06


namespace quotek {

  namespace quant {

    /**
     * Logicalgrid is a research work meant to test if we can process 
     * financial time-series through an array of logical gates.
     * Therefore logicalgrid is a sort of software reproduction of FPGAs (and incidentaly much slower). 
     * This is a meant to work along with genetics programming, to help determine
     * what is the best circuit to process the time series.

     * Notes for vectorization: One solution would be to express time series characteristics 
     * through boolean values. ex: (5min stddev >=20) ? 1: 0;
     *
     * GRID FILE FORMAT: 
     * FIRST LINE: <GRID_WIDTH> <GRID_HEIGHT>
     * Each following lines is composed of the following:
     * <CELL_NUM> <CELL_TYPE> <CONNECTED_TO_CELL_NUM>:<CONNECTED_CELL_INPUT_NUM>,<CONNECTED_TO_CELL_NUM>:<CONNECTED_CELL_INPUT_NUM>
     */

    class logicalconn {
      public:
        logicalconn( void* peer , int input_num );
        ~logicalconn();
        void* peer;
        int input_num;
    };

    class logicalcell {

      public:

        logicalcell();
        logicalcell(int inum);
        ~logicalcell();

        unsigned int fct;
        unsigned int output;
        std::vector<unsigned int> inputs;
        void run();
        void bcast();
        int connect( logicalcell* peer, int input_num );
        std::vector<logicalconn> connections;

        int inum;

    };

    class logicalgrid {
      public:
        logicalgrid(int grid_width, int grid_height );
        ~logicalgrid();

        /** randomize creates a random grid given the initial construct parameters */
        void randomize();

        /** imports a previously saved grid */
        static logicalgrid* import(std::string gridfile);

        /** saves the current grid to file */
        int save(std::string gridfile);
     
        void connect(std::vector<int> c1,  
                     std::vector<int> c2,
                     int input_num);

        void connect(std::string connstring);
        void run();

        logicalcell& at(int x, int y);

        /** 1D version of at(int,int) */
        logicalcell& at(int x);

      private:

        std::vector<quotek::quant::logicalcell> grid;
        int grid_width;
        int grid_height;
        int grid_size;

    };

  }
}


#endif
