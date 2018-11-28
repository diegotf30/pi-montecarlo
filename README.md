# pi-montecarlo
An analysis on obtaining Pi using the Montecarlo method with OpenMP

## Results

| <td colspan=6 align="center"><b>Number of iterations
|-
| <td colspan=1><b>10 <td colspan=1><b>100 <td colspan=1><b>1,000 <td colspan=1><b>10,000 <td colspan=1><b>100,000 <td colspan=1><b>1,000,000
|serial <td colspan=2 align="center">0.002 <td colspan=1>0.003 <td colspan=1>0.002 <td colspan=1>0.011 <td colspan=1>0.054
|reduction_2t <td colspan=1>0.004 <td colspan=1>0.005 <td colspan=1>0.004 <td colspan=1>0.016 <td colspan=1>0.056 <td colspan=1>0.806
|reduction_4t <td colspan=1>0.003 <td colspan=1>0.004 <td colspan=1>0.005 <td colspan=1>0.014 <td colspan=1>0.034 <td colspan=1>0.376
|reduction_8t <td colspan=1>0.005 <td colspan=2 align="center">0.006 <td colspan=1>0.011 <td colspan=1>0.039 <td colspan=1>0.310
|atomic_2t <td colspan=1>0.003 <td colspan=1>0.002 <td colspan=1>0.006 <td colspan=1>0.014 <td colspan=1>0.047 <td colspan=1>0.801
|atomic_4t <td colspan=1>0.003 <td colspan=1>0.004 <td colspan=1>0.005 <td colspan=1>0.014 <td colspan=1>0.036 <td colspan=1>0.278
|atomic_8t <td colspan=1>0.006 <td colspan=1>0.004 <td colspan=1>0.007 <td colspan=1>0.011 <td colspan=1>0.037 <td colspan=1>0.313
|critical_2t <td colspan=2 align="center">0.004 <td colspan=1>0.002 <td colspan=1>0.007 <td colspan=1>0.024 <td colspan=1>0.090
|critical_4t <td colspan=1>0.002 <td colspan=2 align="center">0.004 <td colspan=1>0.007 <td colspan=1>0.019 <td colspan=1>0.203
|critical_8t <td colspan=1>0.006 <td colspan=1>0.005 <td colspan=1>0.006 <td colspan=1>0.011 <td colspan=1>0.028 <td colspan=1>0.251

Without the ```ump_sleep(rand() % 3)``` diretive:

| <td colspan=6 align="center"><b>Number of iterations
|-
| <td colspan=1><b>10 <td colspan=1><b>100 <td colspan=1><b>1,000 <td colspan=1><b>10,000 <td colspan=1><b>100,000 <td colspan=1><b>1,000,000
|serial <td colspan=1>0.003 <td colspan=1>0.007 <td colspan=1>0.056 <td colspan=1>0.587 <td colspan=1>5.833 <td colspan=1>55.18
|reduction_2t <td colspan=2 align="center">0.003 <td colspan=1>0.005 <td colspan=1>0.017 <td colspan=1>0.043 <td colspan=1>0.812
|reduction_4t <td colspan=3 align="center">0.004 <td colspan=1>0.013 <td colspan=1>0.032 <td colspan=1>0.315
|reduction_8t <td colspan=2 align="center">0.005 <td colspan=1>0.004 <td colspan=1>0.012 <td colspan=1>0.039 <td colspan=1>0.314
|atomic_2t <td colspan=1>0.002 <td colspan=1>0.004 <td colspan=1>0.002 <td colspan=1>0.014 <td colspan=1>0.057 <td colspan=1>0.423
|atomic_4t <td colspan=1>0.004 <td colspan=1>0.002 <td colspan=1>0.005 <td colspan=1>0.012 <td colspan=1>0.032 <td colspan=1>0.275
|atomic_8t <td colspan=1>0.002 <td colspan=1>0.006 <td colspan=1>0.004 <td colspan=1>0.009 <td colspan=1>0.040 <td colspan=1>0.308
|critical_2t <td colspan=1>0.003 <td colspan=2 align="center">0.004 <td colspan=1>0.007 <td colspan=1>0.019 <td colspan=1>0.097
|critical_4t <td colspan=3 align="center">0.004 <td colspan=1>0.009 <td colspan=1>0.026 <td colspan=1>0.186
|critical_8t <td colspan=1>0.005 <td colspan=1>0.007 <td colspan=1>0.003 <td colspan=1>0.010 <td colspan=1>0.032 <td colspan=1>0.246
  
And finally, using pthreads instead of OpenMP (using ```usleep()```):

| <td colspan=6 align="center"><b>Number of iterations
|-
| <td colspan=1><b>10 <td colspan=1><b>100 <td colspan=1><b>1,000 <td colspan=1><b>10,000 <td colspan=1><b>100,000 <td colspan=1><b>1,000,000
|mutex_2t <td colspan=1>0.003 <td colspan=1>0.004 <td colspan=1>0.033 <td colspan=1>0.291 <td colspan=1>2.916 <td colspan=1>28.97 
|mutex_4t <td colspan=1>0.003 <td colspan=1>0.005 <td colspan=1>0.018 <td colspan=1>0.150 <td colspan=1>1.488 <td colspan=1>14.85
|mutex_8t <td colspan=2 align="center">0.003 <td colspan=1>0.011 <td colspan=1>0.067 <td colspan=1>0.717 <td colspan=1>7.348

  
### Try it yourself!

You can run the compiled code for each parallelization strategy (as well as the non-paralellized version) in the ```executables/``` folder.


As well you can always compile it yourself using
``` $ gcc serial.c -o serial -fopenmp  ```

And for ```mutex.c``` (which uses pthreads) you can compile it as such:
``` $ gcc mutex.c -o mutex -lpthreads  ```
