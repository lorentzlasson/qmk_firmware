qmk setup

qmk compile -e CONVERT_TO=promicro_rp2040 -kb crkbd -km lorentzlasson
qmk flash -e CONVERT_TO=promicro_rp2040 -kb crkbd -km lorentzlasson

## TODO
