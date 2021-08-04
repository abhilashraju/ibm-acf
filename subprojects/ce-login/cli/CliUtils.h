#include <inttypes.h>
#include <json-c/json.h>

#include <string>
#include <vector>

#ifndef _CLIUTILS_H
#define _CLIUTILS_H

namespace cli
{
bool readBinaryFile(const std::string fileNameParm,
                    std::vector<uint8_t>& bufferParm);
bool writeBinaryFile(const std::string fileNameParm, const uint8_t* bufferParm,
                     const uint64_t bufferLengthParm);
std::string getHexStringFromBinary(const std::vector<uint8_t>& binaryParm);
bool getIntFromJson(json_object* jsonObjectParm, const std::string keyParm,
                    int32_t& resultIntParm);
bool getStringFromJson(json_object* jsonObjectParm, const std::string keyParm,
                       std::string& resultStringParm);
bool createSha512PasswordHash(const std::string& passwordParm,
                              std::vector<uint8_t>& outputHashParm);

} // namespace cli

#endif
