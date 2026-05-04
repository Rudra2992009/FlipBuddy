#ifndef PAYLOAD_GEN_HPP
#define PAYLOAD_GEN_HPP

#include <string>

// High-performance JS payload to be injected into the PDF
const std::string FLIP_JS_PAYLOAD = 
    "function startFlip() {"
    "  app.beginPriv();"
    "  this.layout = 'TwoPageRight';" // Sets side-by-side view
    "  this.zoomType = zoomtype.fitP;" // Fits page to window
    "  app.endPriv();"
    "}"
    "this.setAction('OnPageChange', 'startFlip();');"
    "startFlip();";

#endif