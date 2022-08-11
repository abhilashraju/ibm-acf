#include <inttypes.h>
#include <json-c/json.h>

#include <string>
#include <vector>

#ifndef _CLIUTILS_H
#define _CLIUTILS_H

namespace CeLogin
{
struct Machine;
};

struct option;

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

bool createSha512PasswordHash(const uint8_t* passwordParm,
                              const uint64_t lengthParm,
                              std::vector<uint8_t>& outputHashParm);

bool parseMachineFromString(const std::string& stringParm,
                            CeLogin::Machine& machineParm);

void printHelp(const char* cmdParm, const char* subCmdParm,
               const std::string& introParagraphParm,
               const option optionsParm[], std::string descriptionParm[],
               const uint64_t numOptionsParm);

} // namespace cli

#endif
