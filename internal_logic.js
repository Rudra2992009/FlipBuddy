// This script lives INSIDE the PDF
function onPageTurn(event) {
    // Force the viewer to use 'PageFlip' transition
    app.beginPriv();
    this.viewState = {
        overViewMode: 2, // Two-page view
        pageViewMode: 3  // Flip book mode
    };
    app.endPriv();
}

// Bind the communication layer to the scroll wheel
this.setAction("OnPageChange", "onPageTurn(event);");