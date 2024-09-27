#!/bin/bash

# Start sleep 5 in the background
sleep 5 &

# Get the process ID (PID) of the background sleep command
pid=$!

# Function to show animation (spinning cursor) after the text "swupdate: /"
spin() {
    local spinner="|/-\\"
    local text="swupdate: "
    while kill -0 $pid 2>/dev/null; do
        for i in $(seq 0 3); do
            printf "\r%s%s" "$text" "${spinner:$i:1}"
            sleep 0.2
        done
    done
    printf "\r%sDone!   \n" "$text"
}

# Call the animation function while waiting for the background process to complete
spin

# Wait for the sleep process to complete (though the spinner will stop when the process ends)
wait $pid

