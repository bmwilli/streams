// eJylVF1vmzAUlV_1zK7yqD6Bu2Plo15JtUhq1kypKK9HudTLECVaMjbApS6L89zmGRiRq_0oJB4t7j63N9fY9ROfdKzTjTK9_0flkrLDPQBNk8fnHkeMq9e5RTd0oeqeIyWg_1Du7Wl9rYOX6PvD_0vFmvVY3wQpXb_0FyGETX_18LgJQ4nf36nab6c3F9Onm4TLz0DA6A00fRcg_0g58P0ObN0JcGcKx_1USTknhuE1Zza5KJvTV6MDuA3O05xhcNd_12nIX6NcSZ0j_0sVShdMLGAv_0r5AWijNTb8AGulHQ5q6LKG5lwSm27Tg2ZUKeMUOnYqltLUIZwvvm_19_01IkmkmhfP_11XRRMRWmpZ7ISjuu6lmI3NntrN5rueguq_1yZSCGppplLM2cJx4U9oS_1WIdj7JZBZPU2IWc5NpfJJ_1LkhG96SD04H8IHB4OpDZoKaVFxeHgTMJN7CrYqCmWb7PocdQlXHGNHR2_0Fe7v5E7htu6Ow4_0Kv_0TQ4u5TJaObXdr0ba37QGUyoyiuGBEoAXTKM4qxjlDRjaUZAqpnKOQKk1nz6QgnFMjwgx9I0BIQXHzE8BA5rLYS7fLxctAAUbgWB7gXcYY2M62fH7kM9DcHIz_1A5bnG7K


#ifndef SPL_OPER_INSTANCE_DATAFEED_DATAFEED_H_
#define SPL_OPER_INSTANCE_DATAFEED_DATAFEED_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../../type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.h"


#define MY_OPERATOR DataFeed$OP
#define MY_BASE_OPERATOR DataFeed_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::DataFeed

namespace SPL {
namespace _Operator {
namespace DataFeed {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::uint64 lit$0;
    SPL::list<SPL::rstring > lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::uint32 lit$4;
    SPL::float64 lit$5;
    
    SPL::BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc state$t;
    SPL::uint64 state$c;
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);

private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR
    
{
public:
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
       virtual void process(uint32_t index);
       virtual void allPortsReady();
   
};

} // namespace DataFeed
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_DATAFEED_DATAFEED_H_

