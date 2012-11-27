#include <config.h>
#include "ofp-util.h"
#include "ofp-version-opt.h"
#include "vlog.h"
#include "dynamic-string.h"

VLOG_DEFINE_THIS_MODULE(ofp_version);

static uint32_t allowed_versions = 0;

uint32_t
get_allowed_ofp_versions(void)
{
    return allowed_versions ? allowed_versions : OFPUTIL_DEFAULT_VERSIONS;
}

void
set_allowed_ofp_versions(const char *string)
{
    allowed_versions = ofputil_versions_from_string(string);
}

void
ofp_version_usage(void)
{
    struct ds msg = DS_EMPTY_INITIALIZER;

    ofputil_format_version_bitmap_names(&msg, OFPUTIL_DEFAULT_VERSIONS);
    printf(
        "\nOpen Flow Version options:\n"
        "  -V, --version           display version information\n"
        "  --allowed-ofp-versions  list of allowed Open Flow versions\n"
        "                          (default: %s)\n",
        ds_cstr(&msg));
    ds_destroy(&msg);
}
