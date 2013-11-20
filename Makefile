all:
	mkdir -p bin
	make -C src all
	echo "Run TARGET=installdir make install to install"

install: $(TARGET)
	mkdir -p $(TARGET)/admin
	mkdir -p $(TARGET)/user
	mkdir -p /requests
	mkdir -p /requests/bin
	cp *.php $(TARGET)/
	cp admin/*.php $(TARGET)/admin/
	cp user/*.php $(TARGET)/user/
	cp files/*.txt /requests/
	cp bin/* /requests/bin/
	chmod +s /requests/bin/*
#	echo VPN Request Suite has been installed to $(TARGET)

clean:
	rm -rf bin
