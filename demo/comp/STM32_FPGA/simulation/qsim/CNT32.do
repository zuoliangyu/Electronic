onerror {exit -code 1}
vlib work
vlog -work work CNT32.vo
vlog -work work CNT32.vwf.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.CNT32_vlg_vec_tst -voptargs="+acc"
vcd file -direction CNT32.msim.vcd
vcd add -internal CNT32_vlg_vec_tst/*
vcd add -internal CNT32_vlg_vec_tst/i1/*
run -all
quit -f
