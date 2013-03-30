--- a/net/mac80211/tx.c
+++ b/net/mac80211/tx.c
@@ -2035,6 +2035,7 @@
 		goto fail_rcu;
 	}
 
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,3,0))
 	if (unlikely(!multicast && skb->sk &&
 		     skb_shinfo(skb)->tx_flags & SKBTX_WIFI_STATUS)) {
 		struct sk_buff *orig_skb = skb;
@@ -2063,6 +2064,7 @@
 			skb = orig_skb;
 		}
 	}
+#endif
 
 	/*
 	 * If the skb is shared we need to obtain our own copy.