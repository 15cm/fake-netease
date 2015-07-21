# Install script for directory: /home/hedejin/Taglib/taglib-1.9.1/taglib

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libtag.a")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/lib" TYPE STATIC_LIBRARY FILES "/home/hedejin/Taglib/taglib-1.9.1/taglib/libtag.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/taglib/tag.h;/usr/local/include/taglib/fileref.h;/usr/local/include/taglib/audioproperties.h;/usr/local/include/taglib/taglib_export.h;/usr/local/include/taglib/taglib_config.h;/usr/local/include/taglib/taglib.h;/usr/local/include/taglib/tstring.h;/usr/local/include/taglib/tlist.h;/usr/local/include/taglib/tlist.tcc;/usr/local/include/taglib/tstringlist.h;/usr/local/include/taglib/tbytevector.h;/usr/local/include/taglib/tbytevectorlist.h;/usr/local/include/taglib/tbytevectorstream.h;/usr/local/include/taglib/tiostream.h;/usr/local/include/taglib/tfile.h;/usr/local/include/taglib/tfilestream.h;/usr/local/include/taglib/tmap.h;/usr/local/include/taglib/tmap.tcc;/usr/local/include/taglib/tpropertymap.h;/usr/local/include/taglib/trefcounter.h;/usr/local/include/taglib/tdebuglistener.h;/usr/local/include/taglib/mpegfile.h;/usr/local/include/taglib/mpegproperties.h;/usr/local/include/taglib/mpegheader.h;/usr/local/include/taglib/xingheader.h;/usr/local/include/taglib/id3v1tag.h;/usr/local/include/taglib/id3v1genres.h;/usr/local/include/taglib/id3v2extendedheader.h;/usr/local/include/taglib/id3v2frame.h;/usr/local/include/taglib/id3v2header.h;/usr/local/include/taglib/id3v2synchdata.h;/usr/local/include/taglib/id3v2footer.h;/usr/local/include/taglib/id3v2framefactory.h;/usr/local/include/taglib/id3v2tag.h;/usr/local/include/taglib/attachedpictureframe.h;/usr/local/include/taglib/commentsframe.h;/usr/local/include/taglib/generalencapsulatedobjectframe.h;/usr/local/include/taglib/ownershipframe.h;/usr/local/include/taglib/popularimeterframe.h;/usr/local/include/taglib/privateframe.h;/usr/local/include/taglib/relativevolumeframe.h;/usr/local/include/taglib/textidentificationframe.h;/usr/local/include/taglib/uniquefileidentifierframe.h;/usr/local/include/taglib/unknownframe.h;/usr/local/include/taglib/unsynchronizedlyricsframe.h;/usr/local/include/taglib/urllinkframe.h;/usr/local/include/taglib/oggfile.h;/usr/local/include/taglib/oggpage.h;/usr/local/include/taglib/oggpageheader.h;/usr/local/include/taglib/xiphcomment.h;/usr/local/include/taglib/vorbisfile.h;/usr/local/include/taglib/vorbisproperties.h;/usr/local/include/taglib/oggflacfile.h;/usr/local/include/taglib/speexfile.h;/usr/local/include/taglib/speexproperties.h;/usr/local/include/taglib/opusfile.h;/usr/local/include/taglib/opusproperties.h;/usr/local/include/taglib/flacfile.h;/usr/local/include/taglib/flacpicture.h;/usr/local/include/taglib/flacproperties.h;/usr/local/include/taglib/flacmetadatablock.h;/usr/local/include/taglib/apefile.h;/usr/local/include/taglib/apeproperties.h;/usr/local/include/taglib/apetag.h;/usr/local/include/taglib/apefooter.h;/usr/local/include/taglib/apeitem.h;/usr/local/include/taglib/mpcfile.h;/usr/local/include/taglib/mpcproperties.h;/usr/local/include/taglib/wavpackfile.h;/usr/local/include/taglib/wavpackproperties.h;/usr/local/include/taglib/trueaudiofile.h;/usr/local/include/taglib/trueaudioproperties.h;/usr/local/include/taglib/rifffile.h;/usr/local/include/taglib/aifffile.h;/usr/local/include/taglib/aiffproperties.h;/usr/local/include/taglib/wavfile.h;/usr/local/include/taglib/wavproperties.h;/usr/local/include/taglib/infotag.h;/usr/local/include/taglib/asffile.h;/usr/local/include/taglib/asfproperties.h;/usr/local/include/taglib/asftag.h;/usr/local/include/taglib/asfattribute.h;/usr/local/include/taglib/asfpicture.h;/usr/local/include/taglib/mp4file.h;/usr/local/include/taglib/mp4atom.h;/usr/local/include/taglib/mp4tag.h;/usr/local/include/taglib/mp4item.h;/usr/local/include/taglib/mp4properties.h;/usr/local/include/taglib/mp4coverart.h;/usr/local/include/taglib/modfilebase.h;/usr/local/include/taglib/modfile.h;/usr/local/include/taglib/modtag.h;/usr/local/include/taglib/modproperties.h;/usr/local/include/taglib/itfile.h;/usr/local/include/taglib/itproperties.h;/usr/local/include/taglib/s3mfile.h;/usr/local/include/taglib/s3mproperties.h;/usr/local/include/taglib/xmfile.h;/usr/local/include/taglib/xmproperties.h")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/tag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/fileref.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/audioproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/taglib_export.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib_config.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/taglib.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tstring.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tlist.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tlist.tcc"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tstringlist.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tbytevector.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tbytevectorlist.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tbytevectorstream.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tiostream.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tfilestream.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tmap.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tmap.tcc"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tpropertymap.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/trefcounter.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/toolkit/tdebuglistener.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/mpegfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/mpegproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/mpegheader.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/xingheader.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v1/id3v1tag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v1/id3v1genres.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2extendedheader.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2frame.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2header.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2synchdata.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2footer.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2framefactory.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/id3v2tag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/ownershipframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/privateframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpeg/id3v2/frames/urllinkframe.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/oggfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/oggpage.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/oggpageheader.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/xiphcomment.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/vorbis/vorbisfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/vorbis/vorbisproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/flac/oggflacfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/speex/speexfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/speex/speexproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/opus/opusfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ogg/opus/opusproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/flac/flacfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/flac/flacpicture.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/flac/flacproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/flac/flacmetadatablock.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ape/apefile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ape/apeproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ape/apetag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ape/apefooter.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/ape/apeitem.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpc/mpcfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mpc/mpcproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/wavpack/wavpackfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/wavpack/wavpackproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/trueaudio/trueaudiofile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/trueaudio/trueaudioproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/riff/rifffile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/riff/aiff/aifffile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/riff/aiff/aiffproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/riff/wav/wavfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/riff/wav/wavproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/riff/wav/infotag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/asf/asffile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/asf/asfproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/asf/asftag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/asf/asfattribute.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/asf/asfpicture.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mp4/mp4file.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mp4/mp4atom.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mp4/mp4tag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mp4/mp4item.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mp4/mp4properties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mp4/mp4coverart.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mod/modfilebase.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mod/modfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mod/modtag.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/mod/modproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/it/itfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/it/itproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/s3m/s3mfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/s3m/s3mproperties.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/xm/xmfile.h"
    "/home/hedejin/Taglib/taglib-1.9.1/taglib/xm/xmproperties.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

