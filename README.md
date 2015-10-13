Quotek Algo-trading SDK v2.2
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

![Quotek namespaces scheme](http://docs.quotek.io/sdk/_images/quotek_sdk_ns.png)

Documentation
=============

You can find the full SDK documentation either directly in this repository or on the quotek documentation portal: http://docs.quotek.io/sdk

Setup
=====

In order to get full instructions about how to Setup Quotek SDK in your environment, please look at the documentation page http://docs.quotek.io/sdk/install.html


Changelog
=========

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

2.2 (Q4 2015)
-------------

- Adding of a JSON parser/serializer in the SDK.
- Support of quandl API. 
- Support of more AlchemyAPI functionalities.

2.3 (Q2 2016)
-------------

- Amazon S3 Connector for remote files fetching.
- Amazon Machine Learning API connector.
- Azure Machine learning API connector.
- HDF5 Connector.

2.4 (Q4 2016)
-------------

- Hadoop connector.
- Machine learning algorithms implementation, Part 1.

2.5 (Q2 2017)
-------------

- Machine learning algorithms implementation, Part 2.

Contact
=======

If you want to reach the quotek SDK developpers for any reason, you can send a mail to contact [=at=] quotek.io,
or contact @wintermew or @quotekio on Twitter.
