project(Lanedetection)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})   

find_package( OpenCV REQUIRED )
if( OpenCV_FOUND )
list( APPEND ThirdParty_LIBS ${OpenCV_LIBS} )
    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif( OpenCV_FOUND )

FIND_PACKAGE(OpenMP REQUIRED)  
if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# uncomment this for c++11 support
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
set(${PROJECT_NAME}_SRC  LaneProcessing.cpp ImageTestFunction.cpp VideoProcess.cpp binary.cpp bwareaopen.cpp bwlabel.cpp gray.cpp hsv.cpp isrow.cpp ixamax.cpp mean.cpp morphopAlgo.cpp polyfit.cpp power.cpp processedout.cpp processedout_data.cpp processedout_emxAPI.cpp processedout_emxutil.cpp processedout_initialize.cpp processedout_terminate.cpp processinga.cpp processingb.cpp qrsolve.cpp resize.cpp rtGetInf.cpp rtGetNaN.cpp rt_nonfinite.cpp sobelfilter.cpp sqrt.cpp sum.cpp unwrap.cpp vander.cpp wrap.cpp xgemv.cpp xgeqp3.cpp xgerc.cpp xnrm2.cpp xswap.cpp xzlarf.cpp xzlarfg.cpp)

set(${PROJECT_NAME}_HDR ImageTestFunction.h VideoProcess.h binary.h bwareaopen.h bwlabel.h gray.h hsv.h isrow.h ixamax.h mean.h morphopAlgo.h polyfit.h power.h processedout.h processedout_data.h processedout_emxAPI.h processedout_emxutil.h processedout_initialize.h processedout_types.h processedout_terminate.h processa.h processb.h qrsolve.h resize.h rtGetInf.h rtGetNaN.h rt_nonfinite.h sobelfilter.h sqrt.h sum.h unwrap.h vander.h wrap.h xgemv.h xgeqp3.h xgerc.h xnrm2.h xswap.h xzlarf.h xzlarfg.h rtwtypes.h)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HDR})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

