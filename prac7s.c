#include <stdio.h>
#include <rpc/rpc.h>
#include <rpcsvc/rusers.h>

void *rusers();

main()
{
    if (rpc_reg(RUSERSPROG, RUSERSVERS,
                RUSERSPROC_NUM, rusers,
                xdr_void, xdr_u_long,
                "visible") == -1)
    {
        fprintf(stderr, "Couldn't Register\n");
        exit(1);
    }
    svc_run(); /* Never returns */
    fprintf(stderr, "Error: svc_run returned!\n");
    exit(1);
}