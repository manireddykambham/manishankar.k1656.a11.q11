#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct process
{
      char pn;
      int at, bt, ct, wt, tat,p,s;
}pq [10];
 
int n;
 
void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < n - 1; i++)
      {
            for(j = i + 1; j < n; j++)
            {
                  if(pq [i].at > pq[j].at)
                  {
                        temp = pq[i];
                        pq[i] = pq[j];
                        pq[j] = temp;
                  }}}}
 main()
{
      int i, time = 0, bt= 0,l;
      char c;
      float wait_time = 0, tat= 0, awt, att;
      printf("\n Enter Number of Processe adding: ");
      scanf("%d", &n);
      for(i = 0, c='A'; i < n; i++, c++)
      {
            pq[i].pn = c;
            printf("\n please fill Details For Process[%C]:\n", pq[i].pn);
            printf(" Arrival Time:\t");
            scanf("%d", &pq [i].at );
            printf(" Burst Time:\t");
            scanf("%d", &pq [i].bt);
            printf(" Priority:\t");
            scanf("%d", &pq [i].p);
            pq[i].s = 0;
            bt= bt+ pq[i].bt;
      }
      Arrival_Time_Sorting();
      pq[9].p = -9999;
      printf("\n Process Name\tArrival Time\tBurst Time\tp\tWaiting Time");
      for(time = pq[0].at; time <bt;)
      {
            l= 9;
            for(i = 0; i < n; i++)
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
      awt = wait_time / n;
      att = tat / n;
      printf("\n\n Average waiting time:\t%f\n", awt);
      printf(" Average Turnaround Time:\t%f\n", att);
}
