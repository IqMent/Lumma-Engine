//
// Created by IqMent on 16.03.2025.
//

#ifndef LUMMAENGINE_RANDOM_HPP
#define LUMMAENGINE_RANDOM_HPP


#ifdef __WIN32
#define
#elif defined(__APPLE__)
#define RAND_PATH "/dev/random"
#elif defined(__linux__)
#define RAND_PATH "/dev/random"
#endif



#endif //LUMMAENGINE_RANDOM_HPP
