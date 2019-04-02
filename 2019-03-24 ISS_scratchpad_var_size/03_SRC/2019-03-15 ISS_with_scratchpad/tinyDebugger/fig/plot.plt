set xrange [0:300]
set title "Power Performance"
set xlabel 'time' 
set grid
set style line 1 lt 1 lw 2 lc rgb "orange"
set style line 2 lt 1 lw 2 lc rgb "red"
set style line 3 lt 1 lw 2 lc rgb "blue"
set style line 4 lt 1 lw 2 lc rgb "green"
#set term png
#set output 'plot.png'

### 'fetch'
set ytics nomirror
set yrange [-5:30]
set ytics offset  0, 0
set ylabel offset 0, 0
set ylabel 'voltage (mV)' 
plot "output.txt" using 1:2 t "flash fetch" with lines ls 1
replot "output.txt" using 1:3 t "scratch fetch" with lines ls 2
replot "output.txt" using 1:4 t "decode" with lines ls 3 
replot "output.txt" using 1:5 t "execute" with lines ls 4 

