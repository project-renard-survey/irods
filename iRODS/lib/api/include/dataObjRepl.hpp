/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* dataObjRepl.h - This dataObj may be generated by a program or script
 */

#ifndef DATA_OBJ_REPL_HPP
#define DATA_OBJ_REPL_HPP

/* This is a high level type API call */

#include "rods.hpp"
#include "rcMisc.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"
#include "dataObjWrite.hpp"
#include "dataObjClose.hpp"
#include "dataCopy.hpp"

#if defined(RODS_SERVER)
#define RS_DATA_OBJ_REPL250 rsDataObjRepl250
#define RS_DATA_OBJ_REPL rsDataObjRepl
/* prototype for the server handler */
int
rsDataObjRepl250( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                  transStat_t **transStat );
int
rsDataObjRepl( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
               transferStat_t **transferStat );
int
_rsDataObjRepl( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                transferStat_t *transStat, dataObjInfo_t *outDataObjInfo );
int
_rsDataObjReplUpdate( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                      dataObjInfo_t *srcDataObjInfoHead, dataObjInfo_t *destDataObjInfoHead,
                      transferStat_t *transStat, dataObjInfo_t *oldDataObjInfo );
int
_rsDataObjReplNewCopy( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                       dataObjInfo_t *srcDataObjInfoHead, rescGrpInfo_t *destRescGrpInfo,
                       transferStat_t *transStat, dataObjInfo_t *oldDataObjInfo,
                       dataObjInfo_t *outDataObjInfo );
int
_rsDataObjReplS( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                 dataObjInfo_t *srcDataObjInfo, rescInfo_t *destRescInfo,
                 char *rescGroupName, dataObjInfo_t *destDataObjInfo, int updateFlag );
int
dataObjOpenForRepl( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                    dataObjInfo_t *srcDataObjInfo, rescInfo_t *destRescInfo,
                    char *rescGroupName, dataObjInfo_t *destDataObjInfo, int updateFlag );
int
dataObjCopy( rsComm_t *rsComm, int l1descInx );
int
l3DataCopySingleBuf( rsComm_t *rsComm, int l1descInx );
int
l3DataStageSync( rsComm_t *rsComm, int l1descInx );
int
l3FileSync( rsComm_t *rsComm, int srcL1descInx, int destL1descInx );
int
l3FileStage( rsComm_t *rsComm, int srcL1descInx, int destL1descInx ); // JMC - backport 4527
int _l3FileStage( rsComm_t *rsComm, dataObjInfo_t *srcDataObjInfo, dataObjInfo_t *destDataObjInfo, int mode ); // JMC - backport 4527
int
rsReplAndRequeDataObjInfo( rsComm_t *rsComm,
                           dataObjInfo_t **srcDataObjInfoHead, char *destRescName, char *flagStr );
int
replToCacheRescOfCompObj( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                          dataObjInfo_t *srcDataObjInfoHead, dataObjInfo_t *compObjInfo,
                          dataObjInfo_t *oldDataObjInfo, dataObjInfo_t **outDestDataObjInfo );
int
stageBundledData( rsComm_t *rsComm, dataObjInfo_t **subfileObjInfoHead );
int
unbunAndStageBunfileObj( rsComm_t *rsComm, char *bunfileObjPath,
                         rescInfo_t **outCacheResc );
int
_unbunAndStageBunfileObj( rsComm_t *rsComm, dataObjInfo_t **bunfileObjInfoHead, keyValPair_t* condInput,
                          rescInfo_t **outCacheResc, int rmBunCopyFlag );
int
stageDataFromCompToCache( rsComm_t *rsComm, dataObjInfo_t *compObjInfo,
                          dataObjInfo_t *outCacheObjInfo );
int
stageAndRequeDataToCache( rsComm_t *rsComm, dataObjInfo_t **compObjInfoHead );
int
stageBundledData( rsComm_t *rsComm, dataObjInfo_t **subfileObjInfoHead );
#else
#define RS_DATA_OBJ_REPL NULL
#define RS_DATA_OBJ_REPL250 NULL
#endif

#ifdef __cplusplus
extern "C" {
#endif
    /* prototype for the client call */
    /* rcDataObjRepl - Replicate an iRODS data object.
     * Input -
     *   rcComm_t *conn - The client connection handle.
     *   dataObjInp_t *dataObjInp - generic dataObj input. Relevant items are:
     *      objPath - the path of the data object.
     *      condInput - conditional Input
     *          ALL_KW - update all copies.
     *          DATA_TYPE_KW - "value" = the data type of the file.
     *          REPL_NUM_KW  - "value" = The replica number to use as source
     *              copy. (optional)
     *          RESC_NAME_KW - "value" = The source Resource (optional).
     *          DEST_RESC_NAME_KW - "value" = The destination Resource.
     *          ADMIN_KW - Admin removing other users' files. Only files
     *              in trash can be removed.
     *          BACKUP_RESC_NAME_KW - backup resource (backup mode).
     *   return value - The status of the operation.
     */
    int
    rcDataObjRepl( rcComm_t *conn, dataObjInp_t *dataObjInp );
    int
    _rcDataObjRepl250( rcComm_t *conn, dataObjInp_t *dataObjInp,
                       transStat_t **transStat );
    int
    _rcDataObjRepl( rcComm_t *conn, dataObjInp_t *dataObjInp,
                    transferStat_t **transferStat );
    int
    getCacheDataInfoOfCompObj( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                               dataObjInfo_t *srcDataObjInfoHead, dataObjInfo_t *destDataObjInfoHead,
                               dataObjInfo_t *compDataObjInfo, dataObjInfo_t *oldDataObjInfo,
                               dataObjInfo_t **outDataObjInfo );
    int
    getCacheDataInfoOfCompResc( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                                dataObjInfo_t *srcDataObjInfoHead, dataObjInfo_t *destDataObjInfoHead,
                                rescGrpInfo_t *compRescGrpInfo, dataObjInfo_t *oldDataObjInfo,
                                dataObjInfo_t **outDataObjInfo );
#ifdef __cplusplus
}
#endif
#endif  /* DATA_OBJ_REPL_H */
