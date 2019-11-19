#include <stdio.h>
#include <rpc/rpc.h>
#include <rpcsvc/rusers.h>

main(int argc, char *argv[])
{
    unsigned long nusers;
    int stat;
    stat = callrpc(argv[1], RUSERSPROG, RUSERSVERS, RUSERSPROC_NUM, xdr_void, 0, xdr_u_long, &nusers);
    printf("%d", stat);
    exit(0);
}
