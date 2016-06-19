Pebble.addEventListener('ready',
  function(e) {
    console.log('Pebble JS ready');
  }
);

Pebble.addEventListener('appmessage',
  function(e) {
    console.log('AppMessage received');
}
);
