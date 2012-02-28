#
# CS2110 Testbench
# Runs tests

TEST_DIR=tests

echo "Text mode"
TEST_COUNT=3
PROG=pickle
ARGS=-t
p=1
j=0
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-$p-$i";
    outp="out-$p-$i";
    outp_="out-$p-${i}_";
    ./$PROG $ARGS $TEST_DIR/$inp $TEST_DIR/$outp_;
    diff -bBq $TEST_DIR/$outp $TEST_DIR/$outp_ > /dev/null;
    if [[ $? == 0 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;
echo "Done ($j/$i) passed."

echo "Binary mode"
TEST_COUNT=2
PROG=pickle
ARGS=-b
p=2
j=0
for i in `seq 1 $TEST_COUNT`; do
    echo -n "Running Test $i... "
    inp="in-$p-$i";
    outp="out-$p-$i";
    outp_="out-$p-${i}_";
    ./$PROG $ARGS $TEST_DIR/$inp $TEST_DIR/$outp_;
    diff -bBq $TEST_DIR/$outp $TEST_DIR/$outp_ > /dev/null;
    if [[ $? == 0 ]] ; then
        echo "Passed."
        j=$((j+1))
    else
        echo "Failed."
    fi
done;
echo "Done ($j/$i) passed."
