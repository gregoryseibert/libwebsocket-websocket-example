/*
 * author: 	gregoryseibert
 * date:	20.04.2020
 */

#include <string.h>
#if !defined (LWS_PLUGIN_STATIC)
#include <libwebsockets.h>
#endif

static int protocolCallback(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len)
{
        switch (reason) {
			case LWS_CALLBACK_ESTABLISHED:
				printf("websocket connection established\n");
				fflush(stdout);

				int n = 0;
				char message[10];
				sprintf(message, "test: %d", n );
				lws_write(wsi, message, strlen(message), LWS_WRITE_TEXT);

				n = 1;
				sprintf(message, "test: %d", n );
				lws_write(wsi, message, strlen(message), LWS_WRITE_TEXT);

				break;

			case LWS_CALLBACK_CLOSED:
				printf("websocket connection closed\n");
				fflush(stdout);

				break;

			default:
				break;
        }

        return 0;
}

#define PROTOCOL_WEBSOCKET \
{ \
		"protocol-websocket", \
		protocolCallback, \
		1024, \
		0, NULL, 0 \
}
