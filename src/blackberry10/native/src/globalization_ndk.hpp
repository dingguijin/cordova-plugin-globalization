/*
* Copyright 2013 Research In Motion Limited.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef GLOBALIZATIONNDK_HPP_
#define GLOBALIZATIONNDK_HPP_

#include <string>
#include <pthread.h>

class GlobalizationJS;

namespace webworks {

class GlobalizationNDK {
public:
	explicit GlobalizationNDK(GlobalizationJS *parent = NULL);
	virtual ~GlobalizationNDK();

	// The extension methods are defined here
	std::string globalizationTestString();

	std::string globalizationTestString(const std::string& inputString);

	std::string getGlobalizationProperty();

	void setGlobalizationProperty(const std::string& inputString);

	void globalizationTestAsync(const std::string& callbackId, const std::string& inputString);

	std::string globalizationStartThread(const std::string& callbackId);

	std::string globalizationStopThread();

	bool isThreadHalt();

	void globalizationThreadCallback();

private:
	GlobalizationJS *m_pParent;
	int globalizationProperty;
	int globalizationThreadCount;
	bool threadHalt;
	std::string threadCallbackId;
	pthread_t m_thread;
	pthread_cond_t cond;
	pthread_mutex_t mutex;
};

} // namespace webworks

#endif /* GLOBALIZATIONNDK_H_ */