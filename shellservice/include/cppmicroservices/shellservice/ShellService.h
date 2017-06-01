/*=============================================================================

  Library: CppMicroServices

  Copyright (c) The CppMicroServices developers. See the COPYRIGHT
  file at the top-level directory of this distribution and at
  https://github.com/CppMicroServices/CppMicroServices/COPYRIGHT .

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef CPPMICROSERVICES_SHELLSERVICE_H
#define CPPMICROSERVICES_SHELLSERVICE_H

#include "cppmicroservices/GlobalConfig.h"

#include "cppmicroservices/shellservice/ShellServiceExport.h"

#include <vector>
#include <memory>

namespace cppmicroservices {

class BundleResource;

class US_ShellService_EXPORT ShellService
{
public:

  ShellService();
  ~ShellService();

  void ExecuteCommand(const std::string& cmd);

  std::vector<std::string> GetCompletions(const std::string& in);

private:

  ShellService(const ShellService&);
  ShellService& operator=(const ShellService&);

  void LoadSchemeResource(const BundleResource& res);

  struct Impl;
  std::unique_ptr<Impl> d;
};

}

#endif // CPPMICROSERVICES_SHELLSERVICE_H