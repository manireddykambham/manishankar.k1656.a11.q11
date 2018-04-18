#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct process
{
      char pn;
      int at, bt, ct, wt, tat,p;
      int s;
}pq [10];
 
int limit;
 
void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(pq [i].at > pq[j].at)
                  {
                        temp = pq[i];
                        pq[i] = pq[j];
                        pq[j] = temp;
                  }
            }
      }
}
 
main()
{
      int i, time = 0, bt= 0,l;
      char c;
      float wait_time = 0, tat= 0, average_waiting_time, average_turnaround_time;
      printf("\nEnter Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0, c='A'; i < limit; i++, c++)
      {
            pq[i].pn = c;
            printf("\nEnter Details For Process[%C]:\n", pq[i].pn);
            printf("Enter Arrival Time:\t");
            scanf("%d", &pq [i].at );
            printf("Enter Burst Time:\t");
            scanf("%d", &pq [i].bt);
            printf("Enter Priority:\t");
            scanf("%d", &pq [i].p);
            pq[i].s = 0;
            bt= bt+ pq[i].bt;
      }
      Arrival_Time_Sorting();
      pq[9].p = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tp\tWaiting Time");
      for(time = pq[0].at; time <bt;)
      {
            l= 9;
            for(i = 0; i < limit; i++)
            {
                  if(pq [i].at <= time && pq[i].s != 1 && pq[i].p > pq[l].p)
                  {
                        l= i;
                  }
            }
            time = time + pq[l].bt;
            pq[l].ct = time;
            pq[l].wt = pq[l].ct - pq[l].at - pq[l].bt;
            pq[l].tat = pq[l].ct - pq[l].at;
            pq[l].s = 1;
            wait_time = wait_time + pq[l].wt;
            tat= tat+ pq[l].tat;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", pq[l].pn, pq[l].at, pq[l].bt, pq[l].p, pq[l].wt);
      }
      average_waiting_time = wait_time / limit;
      average_turnaround_time = tat / limit;
      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);
}


