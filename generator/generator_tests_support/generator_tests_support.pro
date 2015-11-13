TARGET = generator_tests_support
TEMPLATE = lib
CONFIG += staticlib warn_on

ROOT_DIR = ../..
DEPENDENCIES = generator map routing indexer platform geometry coding base \
               expat tess2 protobuf tomcrypt osrm succinct

include($$ROOT_DIR/common.pri)

INCLUDEPATH *= $$ROOT_DIR/3party/expat/lib

HEADERS += \
    test_mwm_builder.hpp \

SOURCES += \
    test_mwm_builder.cpp \
