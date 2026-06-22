#!/bin/bash -ax
echo "wakeup" > /sys/kernel/debug/tracing/current_tracer
cat /sys/kernel/debug/tracing/current_tracer
echo 0 > /sys/kernel/debug/tracing/tracing_max_latency
echo 1 > /sys/kernel/debug/tracing/tracing_on
sleep 60
echo 0 > /sys/kernel/debug/tracing/tracing_on

cat /sys/kernel/debug/tracing/trace > ftrace_premptoff.out
echo "nop" > /sys/kernel/debug/tracing/current_tracer
