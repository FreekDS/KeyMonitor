#ifndef KEYLOGGER_KEYRECORDER_H
#define KEYLOGGER_KEYRECORDER_H

#include "Keyboard.h"
#include <thread>
#include <map>
#include <ostream>

/**
 * Records pressed keys
 * This class uses its own thread to record keystrokes.
 */
class KeyRecorder {
private:
    std::thread *my_thread;             /*<Thread used to record keystrokes*/
    bool halt;                          /*<Stops recording the keystrokes*/
    std::map<InputType, int> key_count; /*<Container*/

    /**
     * Function that will be used in the thread.
     * This function records the keys and stores values in key_count
     */
    void monitorKeys();

public:
    /**
     * Constructor for the key recorder.
     * - The thread pointer is initialized as nullptr
     * - The halt boolean is initialized as false
     */
    KeyRecorder();

    /**
     * Destructor for the key recorder.
     * - Stops the monitor function if it is running.
     * - Deletes the thread if it exists
     */
    virtual ~KeyRecorder();

    /**
     * Start monitoring keystrokes by calling this function.
     * A thread is spawned to count the keystrokes.
     */
    bool start();

    /**
     * Stop monitoring keystrokes by calling this function.
     * The running thread will be stopped and deleted.
     */
    bool stop();

    bool pause();

    /**
     * Create a log file containing the amount of presses per key.
     * Note: the .log extension is added automaticly, there is no need to add it to the filename by yourself.
     * @param file_name Name of the output file (default = 'output.log')
     */
    void createLoggingFile(const std::string &file_name = "output");

    /**
     * Overloaded index operator.
     * Will return the amount of presses of a certain key.
     * @param key Key where you want to know the press count off
     * @return The amount of presses of key 'key'
     */
    int operator[](InputType key);

    /**
     * Overloaded stream operator.
     * Allows the use of the '<<' operator to display amount of keypresses of each key.
     * @param os Output stream to stream to.
     * @param recorder Const reference to a KeyRecorder
     * @return The updated output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const KeyRecorder &recorder);
};


#endif //KEYLOGGER_KEYRECORDER_H


