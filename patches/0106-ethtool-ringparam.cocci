@set@
identifier ops, fn;
@@
const struct ethtool_ops ops = {
  .set_ringparam = fn,
  ...
};

@@
identifier set.fn;
identifier dev, rp, krp, extack;
@@
int fn(struct net_device *dev,
       struct ethtool_ringparam *rp
+#if LINUX_VERSION_IS_GEQ(5,17,0)
       , struct kernel_ethtool_ringparam *krp,
       struct netlink_ext_ack *extack
+#endif
      )
{
...
}

@get@
identifier ops, fn;
@@
const struct ethtool_ops ops = {
  .get_ringparam = fn,
  ...
};

@@
identifier get.fn;
identifier dev, rp, krp, extack;
@@
void fn(struct net_device *dev,
        struct ethtool_ringparam *rp
+#if LINUX_VERSION_IS_GEQ(5,17,0)
        , struct kernel_ethtool_ringparam *krp,
        struct netlink_ext_ack *extack
+#endif
       )
{
...
}
