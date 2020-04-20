/*
 * author: 	gregoryseibert
 * date:	20.04.2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libwebsockets.h>
#include <signal.h>
#define LWS_PLUGIN_STATIC
#include "ProtocolWebsocket.c"

static int interrupted, port = 9000;

static struct lws_protocols protocols[] = {
	PROTOCOL_WEBSOCKET,
	{ NULL, NULL, 0, 0 } /* terminator */
};

void sigint_handler(int sig)
{
        interrupted = 1;
}

int main(int argc, const char **argv)
{
		printf("websocket server initializing...\n");
		fflush(stdout);

        struct lws_context_creation_info info;
        struct lws_context *context;
        int n = 0;

        signal(SIGINT, sigint_handler);

        memset(&info, 0, sizeof info); /* otherwise uninitialized garbage */
        info.port = port;
        info.protocols = protocols;
        info.pt_serv_buf_size = 32 * 1024;
        info.options = LWS_SERVER_OPTION_VALIDATE_UTF8 | LWS_SERVER_OPTION_HTTP_HEADERS_SECURITY_BEST_PRACTICES_ENFORCE;

        context = lws_create_context(&info);
        if (!context) {
			lwsl_err("lws init failed\n");
			return 1;
        }

        printf("websocket server starting...\n");
        fflush(stdout);

        while (n >= 0 && !interrupted) {
			n = lws_service(context, 0);
        }

        printf("websocket server stopping...\n");
        fflush(stdout);

        lws_context_destroy(context);

        lwsl_user("Completed %s\n", interrupted == 2 ? "OK" : "failed");

        return interrupted != 2;
}

