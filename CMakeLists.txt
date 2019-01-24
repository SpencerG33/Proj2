cmake_minimum_required(VERSION 3.12)
project(Proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj2 main.cpp FCFS/FCFSQueue.cpp FCFS/FCFSQueue.hpp Queue.hpp FCFS/FCFSQueueNode.cpp FCFS/FCFSQueueNode.hpp Request.cpp Request.hpp PickUp/PickUpQueue.cpp PickUp/PickUpQueue.hpp PickUp/PickUpQueueNode.cpp PickUp/PickUpQueueNode.hpp SameTrack/SameTrackQueue.cpp SameTrack/SameTrackQueue.hpp SameTrack/SameTrackQueueNode.cpp SameTrack/SameTrackQueueNode.hpp LookUp/LookUpQueue.cpp LookUp/LookUpQueue.hpp LookUp/LookUpQueueNode.cpp LookUp/LookUpQueueNode.hpp CLookUp/CLookUpQueue.cpp CLookUp/CLookUpQueue.hpp CLookUp/CLookUpQueueNode.cpp CLookUp/CLookUpQueueNode.hpp EventNode.hpp DiskDoneEvent.cpp DiskDoneEvent.hpp EventQueue.cpp EventQueue.hpp EventNode.cpp Disk.cpp Disk.hpp)