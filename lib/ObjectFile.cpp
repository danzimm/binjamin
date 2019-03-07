#include "ObjectFile.h"
#include "llvm/Object/ObjectFile.h"

using namespace llvm;
using namespace llvm::object;

struct ObjectFile {
  OwningBinary<object::ObjectFile> real;
  ObjectFile(OwningBinary<object::ObjectFile> &&real) : real(std::move(real)) {}
};

::ObjectFile *binj_createObjectFile(const char *path) {
  auto result = object::ObjectFile::createObjectFile(path);
  if (result.takeError())
    return nullptr;
  return new ::ObjectFile(std::move(result.get()));
}

void binj_destroyObjectFile(::ObjectFile *objectFile) {
  delete objectFile;
}

const char *binj_archName(::ObjectFile *objectFile) {
  switch (objectFile->real.getBinary()->getArch()) {
  case Triple::ArchType::arm:
    return "arm";
  case Triple::ArchType::aarch64:
    return "arm64";
  case Triple::ArchType::x86:
    return "x86";
  case Triple::ArchType::x86_64:
    return "x86_64";
  default:
    return "unknown";
  }
}
