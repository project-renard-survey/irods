/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the RENAMERIGHT directory ***/
/* dataObjRename.h - This dataObj may be generated by a program or script
 */

#ifndef DATA_OBJ_RENAME_HPP
#define DATA_OBJ_RENAME_HPP

/* This is a Object File I/O API call */

#include "rods.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "dataObjCopy.hpp"

#ifdef __cplusplus
extern "C" {
#endif
#if defined(RODS_SERVER)
#define RS_DATA_OBJ_RENAME rsDataObjRename
    /* prototype for the server handler */
    int
    rsDataObjRename( rsComm_t *rsComm, dataObjCopyInp_t *dataObjRenameInp );
    int
    _rsDataObjRename( rsComm_t *rsComm, dataObjCopyInp_t *dataObjRenameInp );
    int
    specCollObjRename( rsComm_t *rsComm, dataObjInfo_t *srcDataObjInfo,
                       dataObjInfo_t *destDataObjInfo );
    int
    l3Rename( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo, char *newFileName );
    int
    moveMountedCollObj( rsComm_t *rsComm, dataObjInfo_t *srcDataObjInfo,
                        int srcType, dataObjInp_t *destDataObjInp );
    int
    moveMountedCollDataObj( rsComm_t *rsComm, dataObjInfo_t *srcDataObjInfo,
                            dataObjInp_t *destDataObjInp );
    int
    moveMountedCollCollObj( rsComm_t *rsComm, dataObjInfo_t *srcDataObjInfo,
                            dataObjInp_t *destDataObjInp );
#else
#define RS_DATA_OBJ_RENAME NULL
#endif

    /* prototype for the client call */
    /* rcDataObjRename - Rename a iRODS data object or collection.
     * Input -
     *   rcComm_t *conn - The client connection handle.
     *   dataObjCopyInp_t *dataObjRenameInp - Relevant items are:
     *      dataObjInp_t srcDataObjInp - The source dataObj. Relevant items are:
     *          objPath - the source object path.
     *          oprType - type of rename:
     *              RENAME_DATA_OBJ - rename a data object
     *              RENAME_COLL - rename a collection
     *              RENAME_UNKNOWN_TYPE - rename a data object or collection
     *      destDataObjInp - The destination dataObj. Relevant items are:
     *          objPath - the destination object path.
     * OutPut -
     *    int status of the operation - >= 0 ==> success, < 0 ==> failure.
     */

    int
    rcDataObjRename( rcComm_t *conn, dataObjCopyInp_t *dataObjRenameInp );

#ifdef __cplusplus
}
#endif
#endif  /* DATA_OBJ_RENAME_H */
