Quotek Algo-trading SDK v3.0
============================

Quotek SDK is a C++ programming toolkit that aims to help traders and finance engineers to code
efficient strategies in a fast and easy way.

Built arround the recent C++11 programming concepts, Quotek is blazing fast but also remains trivial to use. Quotek SDK is also 
a full part of the quotek SaaS algo-trading solution (see http://quotek.io for more details).

Features
========

The goal behind Quotek SDK is to offer the maximum number of useful functions to the IT Quants. Beyond them you can find:

- Quantitative analysis functions.
- Stochastic calculus processes.
- Machine learning algorithms and API Bindings (Alchemy API..).
- Quotes historical data and newsfeed fetchers ( Yahoo Finance, RSS Feeds..).

The following scheme summurizes all the features which are already available in the SDK:

![Quotek namespaces scheme](http://docs.quotek.io/sdk3/_images/quotek_namespace.png)

Documentation
=============

You can find the full SDK documentation either directly in this repository or on the quotek documentation portal: http://docs.quotek.io/sdk3

Setup
=====

In order to get full instructions about how to Setup Quotek SDK in your environment, please look at the documentation page http://docs.quotek.io/sdk3/install.html

Changelog
=========

v3.0.0
------

  - [ML] The first Machine Learning Algorithms are now implemnted: Linear Regression, Classification, Non-linear functions, etc..
  - [GEN] SDK now embedds the Eigen C++ Linear Algebra library (see http://eigen.tuxfamily.org ), and an additional set of numerical solvers (cppoptlib).
  - [TA] Implemented T-EMA oscillator.
  - [QUANT] New moving average: Triple-exponential.
  - [TSA] Implemented FFT-Based autoregression filter.
  - [TSA][Experimental][Undoc] SDK now has a kalman filter implementation.
  - [GEN][Experimental][Undoc] Implementation of an Imap client to fetch email data.
  - [GEN] Started benchmarking of the most important functions of the SDK, with the help of Google Benchmark.
  - [DOC] Improved documentation: The documentation of the SDK is now much more complete and clear.
  - [GEN] SDK now has its own implementation of a JSON parser.
  - [GEN] Removed the array_xd classes for support of n-dimensions arrays. Now the SDK benefits of Eigen custom classes.
  - [GEN] Also plenty of bugfixes were passed !.

v2.2.2
------

  - Added eToro OpenBook API Client.

v2.2.1
------

  - Added N-dimensions array classes, specially crafted for performance and ease of use.
  - Added a new function: fibo_extensions, which computes the fibonacci extensions (127.2% to 261.8% ) of the provided time-series.
  - Improved SDK Documentation.

v2.2
----

  - Implemented Quandl API client in SDK.
  - Added support for AlchemyAPI function "Ranked Taxonomy".
  - Interface Changes in quotek::quant functions: Now functions use quotek::data::records containers instead of vector<quotek::data::record>, which is must more coherent and powerful.
  - Bugfix: uninitialized std::tm in p_strptime was triggering random behaviour when seconds not present in date string.

v2.1.3
------

  - Added Visual Studio 2015 Project Template.

v2.1.2
------

  - Multiple bugfixes regarding win64 version: 

     * Incorrect curl headers distribution.
     * Bug in quotek.hpp: wrong sub include order.

v2.1.1
------

  - Improvements on Alchemy API connector: better errors handling, change in quotek::ml::sentiment structure by replacing bool positive by std::string sentimentstr.

  - Added new TA function: fibo_retrace() which allows to compute fibonacci retracement levels for a time-series, along with a new structure: quotek::quand::fibo_levels

  - Added extra function in twitter connector: search(term,nb_results,search_type,lang) In order to refine your searches and extract only what you want as search results.

  - strategy object was removed from the quotek::core namespace in order to improve SDK compatibility with Quotek SaaS


v2.1.0
------

  - Added Twitter connector, to help analyze twitter feeds in your algos.
  - Added CSV importer, to help importing financial data stored in CSV files.

v2.0.0
------

  - Initial Release

SDK Roadmap
===========

You'll find below the main milestones of the Quotek SDK. To sum up, the next releases will focus on implementing Machine learning, deep learning, 
and new datasource connectors.

Notes about the roadmap: 
-----------------------

This roadmap is potentially subject to heavy changes, given the way and pace technology and business move.
To see the roadmap history, just navigate through the different version commits.

3.1 (Q1 2017)
-------------

- Machine learning Algorithms implementation, part2 (Neural-Nets, CNNs, RNNs, LSTM.. )
- Work on Python Support, part2
- Integration/Implementation of a kdb+ Connector.
- Integration/Implementation of an odbc connector.
- New TA and TSA functions.

3.2 (Q3 2017)(Possible Improvements)
------------------------------------

- Hadoop Connector
- HDF5 Connector
- New TA and TSA functions.

Contact
=======

If you want to reach the quotek SDK developpers for any reason, you can send a mail to contact [=at=] quotek.io,
or contact @wintermew or @quotekio on Twitter.
