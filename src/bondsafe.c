#include "bondsafe.h"

int dev_id = -1;
int sock = 0;
char* bond_mac_addr = NULL;


bool scan_query() {
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };

    dev_id = hci_get_route(NULL);
    sock = hci_open_dev( dev_id );
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    len  = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    
    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("hci_inquiry");

    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), 
            name, 0) < 0)
        strcpy(name, "[unknown]");
        printf("%s  %s\n", addr, name);
    }

    free( ii );
    close( sock );
    return 0;
}


int get_device() {
	return hci_get_route(NULL);
}

bool validate_args(int argc, char** argv) {
	int i = 0;
	if(true != isMAC(argv[0])) {
		fprintf(stderr,"Bad MAC Address\n");
		return false;
	}
	argv++;
	argc--;	
	for(i = 0;i < argc;i++) {
		if(true != valid_arg_command(argv[i])) {
			fprintf(stderr,"Invalid argument: %s", argv[i]);
			return false;
		}
			
	}
	return true;
}
	

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("bondsafe [MAC Address] <del/umt/cmd:PATH>\n");
		printf("\tMAC Address in 17 character format: 00:11:22:33:44:55\n");
		printf("\tRepeat as many rm/unmounts as you wish\n");
	}
	argv++;
	argc--;
	if (true != validate_args(argc,argv)) {
		return BAD_ARGS_ERROR;
	}
	return OK_ERROR;
}
