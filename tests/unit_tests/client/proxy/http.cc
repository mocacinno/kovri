/**                                                                                           //
 * Copyright (c) 2013-2016, The Kovri I2P Router Project                                      //
 *                                                                                            //
 * All rights reserved.                                                                       //
 *                                                                                            //
 * Redistribution and use in source and binary forms, with or without modification, are       //
 * permitted provided that the following conditions are met:                                  //
 *                                                                                            //
 * 1. Redistributions of source code must retain the above copyright notice, this list of     //
 *    conditions and the following disclaimer.                                                //
 *                                                                                            //
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list     //
 *    of conditions and the following disclaimer in the documentation and/or other            //
 *    materials provided with the distribution.                                               //
 *                                                                                            //
 * 3. Neither the name of the copyright holder nor the names of its contributors may be       //
 *    used to endorse or promote products derived from this software without specific         //
 *    prior written permission.                                                               //
 *                                                                                            //
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY        //
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF    //
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL     //
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,       //
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,               //
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    //
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,          //
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF    //
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.               //
 *                                                                                            //
 * Parts of the project are originally copyright (c) 2013-2015 The PurpleI2P Project          //
 */
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "client/proxy/http.h"

BOOST_AUTO_TEST_SUITE(HTTPPProtocolTests)

BOOST_AUTO_TEST_CASE(Short) {
  kovri::client::HTTPMessage tmp;
  std::string tmpData = "GET guzzi.i2p HTTP/1.1";
  BOOST_CHECK(!tmp.HandleData(tmpData));
}
BOOST_AUTO_TEST_CASE(requestLineBad) {
  kovri::client::HTTPMessage tmp;
  std::string tmpData = "GET HTTP/1.1";
  BOOST_CHECK(!tmp.HandleData(tmpData));
}
BOOST_AUTO_TEST_CASE(noHeadersAtAll) {
  kovri::client::HTTPMessage tmp;
  std::string tmpData = "\r\n";
  BOOST_CHECK(!tmp.HandleData(tmpData));
}
BOOST_AUTO_TEST_CASE(ok) {
  kovri::client::HTTPMessage tmp;
  std::string tmpData = "GET guzzi.i2p ";
  tmpData+="HTTP/1.1\r\nUser-Agent: dummy\r\n\r\n";
  BOOST_CHECK(tmp.HandleData(tmpData));
}

BOOST_AUTO_TEST_SUITE_END()
