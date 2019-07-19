/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_myntlabs_pgn_core_BRCoreMerkleBlock */

#ifndef _Included_org_myntlabs_pgn_core_BRCoreMerkleBlock
#define _Included_org_myntlabs_pgn_core_BRCoreMerkleBlock
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    createJniCoreMerkleBlock
 * Signature: ([BI)J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_createJniCoreMerkleBlock
  (JNIEnv *, jclass, jbyteArray, jint);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    createJniCoreMerkleBlockEmpty
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_createJniCoreMerkleBlockEmpty
  (JNIEnv *, jclass);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getBlockHash
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getBlockHash
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getVersion
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getVersion
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getPrevBlockHash
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getPrevBlockHash
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getRootBlockHash
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getRootBlockHash
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getTimestamp
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getTimestamp
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getTarget
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getTarget
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getNonce
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getNonce
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getTransactionCount
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getTransactionCount
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    getHeight
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_getHeight
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    serialize
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_serialize
  (JNIEnv *, jobject);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    isValid
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_isValid
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    containsTransactionHash
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_containsTransactionHash
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     org_myntlabs_pgn_core_BRCoreMerkleBlock
 * Method:    disposeNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_myntlabs_pgn_core_BRCoreMerkleBlock_disposeNative
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif