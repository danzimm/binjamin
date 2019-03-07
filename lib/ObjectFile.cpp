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
