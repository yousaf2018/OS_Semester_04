# -*- coding: utf-8 -*-
"""
Crearrival_timeed on Thu Mar 12 22:18:47 2020

@author: Mahmood Yousaf
"""
def findWaitingTime(process, n, burst_time, waiting_time, arrival_time):
    serve_time = [0]*n
    serve_time[0]=0
    waiting_time[0]=0
    #loop for to calculate each process waiting time
    for i in range(1, n):
        serve_time[i] = (serve_time[i - 1] + burst_time[i - 1])
        waiting_time[i] = serve_time[i] - arrival_time[i] 
        #if waiting time is negative than it means process is in ready state
        if waiting_time[i] < 0:
            waiting_time[i] = 0
#funtion to calculte turn around time for each process
def findTurnAroundTime(process, n, burst_time, waiting_time, turn_around_time):
    for i in range(n):
        turn_around_time[i] = burst_time[i] + waiting_time[i]  
def find_avg_time(process, n, burst_time, arrival_time):
    #decalring arrays for calculating averge time 
    waiting_time = [0] * n 
    turn_around_time = [0] * n  
    #funtion to find waiting time for each process
    findWaitingTime(process, n, burst_time, waiting_time, arrival_time) 
    #function to find turn around time  for each process
    findTurnAroundTime(process, n, burst_time, waiting_time, turn_around_time) 
    total_wait_tim = 0
    total_turn_arn_time = 0
    #calculating total time for calculating avergae time 
    for i in range(n):
        total_wait_tim = total_wait_tim + waiting_time[i] 
        total_turn_arn_time=total_turn_arn_time+turn_around_time[i]
    with open("results.txt","a") as file:
        file.write(f"Avergae waiting time in FCFS for all processess is {total_wait_tim/n}\n")
        file.write(f"Turn around time in FCFS for all processess is {total_turn_arn_time/n}\n")
        file.write(f"Avergae Respose time in FCFS for all processess is {total_wait_tim/n}\n")
        file.close()
    print(f"Avergae waiting time in FCFS for all processess is {total_wait_tim/n}")
    print(f"Turn around time in FCFS for all processess is {total_turn_arn_time/n}")
    print(f"Avergae Respose time in FCFS for all processess is {total_wait_tim/n}")
#Code implementurn_around_timeion starts from here
import random
process = [0 for i in range(0,10000)]
burst_time = [0 for i in range(0,10000)]
arrival_time = [0 for i in range(0,10000)]
priority = [0 for i in range(0,10000)]
with open("jobs_10000.csv","r") as file:
    i=0
    reader_handler = csv.reader(file)
    for row in reader_handler:
        process[i]=int(row[0])
        arrival_time[i]=int(row[1])
        burst_time[i]=int(row[2])
        priority[i]=int(row[3])
        i += 1
size=len(process) 
find_avg_time(process, size, burst_time,arrival_time) 