#ifndef EMPTYCACHEEXCEPTION_H
#define EMPTYCACHEEXCEPTION_H

class EmptyCacheException : public std::runtime_error {
public:
    explicit EmptyCacheException(const std::string& message)
        : std::runtime_error("EmptyCacheException: " + message) {}
};

class WrongArgumentsCountException : public std::runtime_error {
public:
    explicit WrongArgumentsCountException(const std::string& message)
        : std::runtime_error("WrongArgumentsCountException: " + message) {}
};

#endif