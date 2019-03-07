#ifndef BINJAMIN_OBJECTFILE_H
#define BINJAMIN_OBJECTFILE_H

#ifdef __cplusplus
extern "C" {
#endif

struct ObjectFile;
typedef struct ObjectFile ObjectFile;

ObjectFile *binj_createObjectFile(const char *path);
void binj_destroyObjectFile(ObjectFile *);

#ifdef __cplusplus
}
#endif

#endif
