#ifndef REDIRECTIONPOLICY_HPP
#define REDIRECTIONPOLICY_HPP

namespace transformer
{
    enum ForwardingPolicy{
        SINGLE_SHOT,
        DOWNSAMPLE_BY_TIME,
        DOWNSAMPLE_BY_NSAMPLE,
        REDIRECT_ALL
    };
    struct ForwardingPolicyConfig
    {
        ForwardingPolicy policy;
        //* Ignored if policy == SINGLE_SHOT or REDURECT_ALL
        //* If policy == DOWNSAMPLE_BY_TIME, an incoming sample is only forwarded,
        //if there was no sample rediretec < arg seconds ago.
        //* if policy == DOWNSAMPLE_BY_NSAMPLE, only evere arg sample will be
        //forwarded
        double arg;
    };
}

#endif

