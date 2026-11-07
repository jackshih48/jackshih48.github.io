// 讓瀏覽器把「記一筆」當成可安裝的 App；資料一律即時向伺服器讀取，不做離線快取
self.addEventListener('install', () => self.skipWaiting());
self.addEventListener('activate', (e) => e.waitUntil(self.clients.claim()));
self.addEventListener('fetch', (e) => {
  e.respondWith(fetch(e.request));
});
