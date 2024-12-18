#ifndef EMPTYCACHEEXCEPTION_H
#define EMPTYCACHEEXCEPTION_H

class EmptyCacheException : public std::runtime_error {
public:
    explicit EmptyCacheException(const std::string& message)
        : std::runtime_error("EmptyCacheException: " + message) {}
};


#endif