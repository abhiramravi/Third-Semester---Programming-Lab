#
# CS2110 Testbench
# Runs tests

TEST_DIR=tests
TEST_COUNT=5
PROG=area
ARGS=

j=0
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-$i";
    outp="out-$i";
    outp_="out-${i}_";
    ./$PROG $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
	v=$(echo "1 - `cat $TEST_DIR/$outp`/`cat $TEST_DIR/$outp_` < 0.01" | bc -l)
    if [[ $v == 1 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;
echo "Done ($j/$i) passed."
