/**
 Hecate Distributed Server

 Copyright (C) 2013 Sean Ryan <sryan@evercrack.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 */

/*
 * Local Includes
 */
#include "Broker.hpp"

/*
 * System Includes
 */
#include <iostream>
#include <unistd.h> /* daemon(), getpid() */
#include <signal.h>
#include <cstdlib> /* getenv() because boost po env parsing sucks */
#include <fstream>
#include <glog/logging.h>

/*
	Entry point
*/
int main(int argc, char** argv)
{

	/*
	 * Initialize Logging
	 */
	google::InitGoogleLogging("");


	/*
	 * Environment Wrangling
	 */
	const char *appenv = std::getenv("HECATE_HOME");
	const char *home  = std::getenv("HOME");
	bool config_found = false;

	/**
	 * Create our metaserver
	 */
	std::cout << "Hecate Broker" << std::endl;
	std::cout << "Signature  : " << SERVER_SIGNATURE << std::endl;
	std::cout << "Built By   : " << BUILD_USER << std::endl;
	std::cout << "Build Host : " << BUILD_HOST << std::endl;
	std::cout << "Build ID : " << BUILD_NUM << std::endl;

	try
	{
		/**
		 * This is the async loop
		 */
		std::cout << "Main Async Loop" << std::endl;
	}
	catch (std::exception& e)
	{
		/*
		 * This will catch exceptions during the startup etc
		 */
		std::cerr << "Exception: " << e.what() << std::endl;
		google::FlushLogFiles(google::INFO);
	}
	LOG(INFO) << "All Done!";
	google::FlushLogFiles(google::INFO);
	return 0;
}
