

alert() #just printing alert here
{
	message="Alert!!"
	echo "$message" | tee -a "$log_file" # i used tee -a so that the terminal also shows the echo statements and then they are aslo written in the log file named arham.log
}

# threhsolds ki valies set k rha

disk_threshold=30
cpu_threshold=30
memory_threshold=10
log_file="/home/arham/Desktop/OS thoery/Assignment # 1/arham.log"
max_log_size=10M


while true; do
    # data is stored in teh file after each print in terminal
    # Disk usage calulations and then writng alert call
    disk_usage=$(df -h --output=pcent / | sed '1d' | awk '{printf "%.2f", $1}')  #df displays disk usage and used output=pcent to output the % only
    if (( $(echo "$disk_usage > $disk_threshold" | bc -l) )); then # cheing the threshold using if , if har jagah yehi kr rhee hy
        alert "Disk usage exceeds $disk_threshold%: $disk_usage"
	echo "Disk usage value: $disk_usage" | tee -a "$log_file" 
        echo "Disk usage exceeded" | tee -a "$log_file"
        
    fi

    # CPU Usage Monitoring and then calling alert 
    cpu_usage=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/")
    if (( $(echo "$cpu_usage > $cpu_threshold" | bc -l) )); then
        alert "CPU usage exceeds $cpu_threshold%: $cpu_usage%"

	echo "CPU usage value: $cpu_usage" | tee -a "$log_file"
        echo "CPU usage exceeded" | tee -a "$log_file"
        
    fi

    # Memory Usage Monitoring and then alert is called if it is below thershold , in the above we were checking if it was above threhsold
    free_mem=$(free --mega | awk '/Mem/{print $4}')  # free mega displays the free memeory
    total_mem=$(free --mega | awk '/Mem/{print $2}') 
    memory_usage=$(echo "scale=2; ($total_mem - $free_mem) * 100 / $total_mem" | bc) 
    if (( $(echo "$memory_usage < $memory_threshold" | bc -l) )); then
        alert "Memory usage falls below $memory_threshold%: $memory_usage%"

	echo "Memory usage value: $memory_usage" | tee -a "$log_file"
        echo "Memory usage exceeded" | tee -a "$log_file"
        
    fi

    # Log Rotation means that new file is made when old one is filled upto 10mb
    if [ -f "$log_file" ]; then # -f tells us if the path to the file is the one we need or not
        log_size=$(du -b "$log_file" | awk '{print $1}')
        if [ "$log_size" -gt "$(($(echo "$max_log_size" | tr -d '[:alpha:]') * 1024))" ]; then
            mv "$log_file" "$log_file.old"
            touch "$log_file"
            alert "Log file rotated: $log_file"
        fi
    fi

    sleep 10s
done

