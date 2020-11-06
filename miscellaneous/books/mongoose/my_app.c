// Copyright (c) 2015 Cesanta Software Limited
// All rights reserved
#define  OIE_URI_FINISH                 "/oie.cgi"

#include "mongoose.h"

char FilePath[100] ="/redirect.html";

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

static void ev_handler(struct mg_connection *nc, int ev, void *p) {
  switch (ev)
  {
    case MG_EV_HTTP_REQUEST:
    {
	   printf("receive new request\n");
      struct http_message *pHttp = (struct http_message *)malloc(sizeof(struct http_message ));
      if (pHttp)
      {
        memcpy(pHttp,p,sizeof(struct http_message));

        //if (mg_vcmp(&pHttp->uri, OIE_URI_FINISH) == 0)
        {
          pHttp->uri.p= FilePath;
          pHttp->uri.len= strlen(FilePath);
        }
        //Responde webBrower Client
        mg_serve_http(nc, pHttp, s_http_server_opts);
        free(pHttp);
        pHttp = NULL;
      }
    }
    break;
    default:
      break;
    //mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);
  }
}

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *nc;

  mg_mgr_init(&mgr, NULL);
  nc = mg_bind(&mgr, s_http_port, ev_handler);

  // Set up HTTP server parameters
  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.document_root = "www";  // Serve current directory
  s_http_server_opts.dav_document_root = ".";  // Allow access via WebDav
  s_http_server_opts.enable_directory_listing = "yes";

  printf("Starting web server on port %s\n", s_http_port);
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}
