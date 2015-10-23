/*
Quotek Strategies SDK 2.0
Copyright 2013-2015 Quotek SAS
http://www.quotek.io
*/

#include <quotek/broker.hpp>
#include <quotek/techanalysis.hpp>
#include <quotek/generators.hpp>
#include <quotek/quant.hpp>
#include <iostream>

#define EPSILON 0.01

void test_macd(quotek::data::records& recs) {

  std::vector<quotek::data::records> macdr = quotek::ta::MACD(recs,12,26,9);

  assert(macdr.size() == 2);
  assert(macdr[0].size() > 0);
  assert(macdr[1].size() > 0);
  assert(macdr[0].size() > macdr[1].size() );
  assert( quotek::quant::crosses(macdr[0],macdr[1]) );
  
}

void test_fibo_retr() {
 
  quotek::data::records recs;
  recs.append(0,0);
  recs.append(1,100);

  quotek::quant::fibo_ret fl = quotek::ta::fibo_retrace(recs);

  assert(fl.p0 == 0);
  assert( fabs( fl.p23 - 23.6) < EPSILON );
  assert(fl.p50 == 50); 
  assert( fabs( fl.p38 - 38.2) < EPSILON );
  assert( fabs( fl.p61 - 61.8) < EPSILON );
  assert(fl.p100 == 100);
  
}

void test_fibo_ext() {
 
  quotek::data::records recs;
  recs.append(0,0);
  recs.append(1,100);

  quotek::quant::fibo_ext fl = quotek::ta::fibo_extension(recs);

  assert(fl.p100 == 100 );
  assert( fabs( fl.p127 - 127.2) < EPSILON );
  assert( fabs( fl.p161 - 161.8) < EPSILON );
  assert( fl.p200 == 200 );
  assert(fabs( fl.p261 - 261.8) < EPSILON );
  
}




int main() {
  quotek::data::records f1 = quotek::rand::generators::normal(100,4500,30);
  test_macd(f1);
  test_fibo_retr();
  test_fibo_ext();

}
