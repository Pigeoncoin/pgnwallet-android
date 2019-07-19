DIR=$(shell pwd)
JAVA_DIR=${JAVA_HOME}

CINC_DIR=/usr/include

JNI_LIB=libCore.jnilib

JNI_SRCS=org_myntlabs_pgn_core_BRCoreAddress.c \
	org_myntlabs_pgn_core_BRCoreChainParams.c \
	org_myntlabs_pgn_core_BRCoreJniReference.c \
	org_myntlabs_pgn_core_BRCoreKey.c \
	org_myntlabs_pgn_core_BRCoreMasterPubKey.c \
	org_myntlabs_pgn_core_BRCoreMerkleBlock.c \
	org_myntlabs_pgn_core_BRCorePaymentProtocol.c \
	org_myntlabs_pgn_core_BRCorePeer.c \
	org_myntlabs_pgn_core_BRCorePeerManager.c \
	org_myntlabs_pgn_core_BRCoreTransaction.c \
	org_myntlabs_pgn_core_BRCoreTransactionInput.c \
	org_myntlabs_pgn_core_BRCoreTransactionOutput.c \
	org_myntlabs_pgn_core_BRCoreWallet.c \
	BRCoreJni.c

JNI_OBJS=$(JNI_SRCS:.c=.o)

# JNI Header Files that we are interest in keeping (that are not empty)
JNI_HDRS=$(JNI_SRCS:.c=.h)

JAVA_SRCS=root/org/myntlabs/pgn/core/BRCoreAddress.java \
	root/org/myntlabs/pgn/core/BRCoreChainParams.java \
	root/org/myntlabs/pgn/core/BRCoreJniReference.java \
	root/org/myntlabs/pgn/core/BRCoreKey.java \
	root/org/myntlabs/pgn/core/BRCoreMasterPubKey.java \
	root/org/myntlabs/pgn/core/BRCoreMerkleBlock.java \
	root/org/myntlabs/pgn/core/BRCorePaymentProtocolEncryptedMessage.java \
	root/org/myntlabs/pgn/core/BRCorePaymentProtocolInvoiceRequest.java \
	root/org/myntlabs/pgn/core/BRCorePaymentProtocolMessage.java \
	root/org/myntlabs/pgn/core/BRCorePaymentProtocolPayment.java \
	root/org/myntlabs/pgn/core/BRCorePaymentProtocolACK.java \
	root/org/myntlabs/pgn/core/BRCorePaymentProtocolRequest.java \
	root/org/myntlabs/pgn/core/BRCorePeer.java \
	root/org/myntlabs/pgn/core/BRCorePeerManager.java \
	root/org/myntlabs/pgn/core/BRCoreTransaction.java \
	root/org/myntlabs/pgn/core/BRCoreTransactionInput.java \
	root/org/myntlabs/pgn/core/BRCoreTransactionOutput.java \
	root/org/myntlabs/pgn/core/BRCoreWallet.java \
	root/org/myntlabs/pgn/core/BRCoreWalletManager.java \
	root/org/myntlabs/pgn/core/test/BRWalletManager.java

JAVA_OBJS=$(JAVA_SRCS:.java=.class)

CORE_SRCS=/core/BRAddress.c \
	/core/BRBIP32Sequence.c \
	/core/BRBIP38Key.c \
	/core/BRBIP39Mnemonic.c \
	/core/BRBase58.c \
	/core/BRBech32.c \
	/core/BRBloomFilter.c \
	/core/BRCrypto.c \
	/core/BRKey.c \
	/core/BRMerkleBlock.c \
	/core/BRPaymentProtocol.c \
	/core/BRPeer.c \
	/core/BRPeerManager.c \
	/core/BRSet.c \
	/core/BRTransaction.c \
	/core/BRWallet.c \

CORE_OBJS=$(CORE_SRCS:.c=.o)

CFLAGS=-I$(JAVA_HOME)/include \
	-I$(JAVA_HOME)/include/darwin \
	-I$(CINC_DIR) \
	-I$(CINC_DIR)/malloc \
	-I/core \
	-I/core/secp256k1 \
	-Wno-nullability-completeness -Wno-format-extra-args -Wno-unknown-warning-option

compile: $(JNI_LIB) java_comp

test: $(JNI_LIB) java_comp
	java -Xss1m -Dwallet.test -classpath build -Djava.library.path=. \
		 org.myntlabs.pgn.core.test.BRWalletManager $(ARGS) # -D.

debug: $(JNI_LIB) java_comp
	java -Xss1m -Xdebug -Xrunjdwp:transport=dt_socket,address=8008,server=y,suspend=n \
		 -Dwallet.test -classpath build -Djava.library.path=. \
		 org.myntlabs.pgn.core.test.BRWalletManager $(ARGS) # -D.

$(JNI_LIB): $(JNI_OBJS) $(CORE_OBJS)
	cc -dynamiclib -o $(JNI_LIB) $(JNI_OBJS) $(CORE_OBJS)

java_comp:	FORCE
	@mkdir -p build
	javac -d build $(JAVA_SRCS)

jni_hdr: java_comp
	@(cd build/org/myntlabs/pgn/core; \
	  for class in BRCore*.class; do \
	      javah -jni -d $(DIR) -classpath $(DIR)/build org.myntlabs.pgn.core.$${class%%.class}; \
	  done)
	@rm -f org_myntlabs_pgn_core_BRCoreWalletManager.h org_myntlabs_pgn_core_BRCore*_*.h .h

clean:
	rm -rf build $(JNI_OBJS) $(CORE_OBJS) $(JAVA_OBJS) $(JNI_LIB)

FORCE:

#	-Wno-nullability-completeness


# Generate Headers:
# 	javac Foo.java
# 	javah -jni -d <location> Foo
# Implement Foo.c
# Generate Foo.so
# 	cc -I<path to jni.h> -I<path to jni_md.h> -I<path to std> -c Foo.c
# 	cc -dynamiclib -o libFoo.jnilib Foo.o Bar.o

# 	<path-to-jni-md>=/Library/Java/JavaVirtualMachines/jdk1.8.0_151.jdk/Contents/Home/include/darwin
# 	<path-to-jni>=/Library/Java/JavaVirtualMachines/jdk1.8.0_151.jdk/Contents/Home/include
# 	<path-to-std>=/…/Xcode.app/Contents/Dev…/Platforms/MacOSX.platform/Dev…/SDKs/MacOSX.sdk/usr/include
# Run Foo
# 	java -Djava.library.path=/Users/ebg Foo
#

# (cd ${APP}/app/build/intermediates/classes/debug/org/myntlabs/pgn/core; for class in BRCore*.class; do \
#     javah -jni -d ${APP}/app/src/main/cpp/myntlabs-core/Java/ \
#	-classpath ${APP}/app/build/intermediates/classes/debug/ \
#	org.myntlabs.pgn.core.${class%%.class}; \
#	done)
# 15RBcXQMTfebbAfUFeBbcDfs1fVvPayWdU
