// eJylU2tPwjAUzf0nxPhhS3Rl_0G4MyTDOxMwJQXx8MmUW1tC1sy0i_1Hq7Moj4iBqzfdi9O_0fu3NMzXfJAUU4Mk4JwjOOpyIxUEELTXi3YCgK0vM28pKhDL2fqqt9specv14tjk9z0jy4XVyeLhT5J5s3ZSzrZS_1rHr2lyM0yj24s8L0WcTx5iNriPnweDHu1Fw26ndxfkW9_1Mnvxh9iSKD6LrTlZNq9RyZrab0O8mGCttFBNjcL1w2WPC7LUAAOWyoGioGBFozAwaFjPGOUOWQkmhkS45Sqk29KlLFOGccqYLtEtASEErXyp3WCnV_0mv_10A4MlDMbYB8yKQTNqsM4k2LExrBaYyRIQdcV36gYTO1mh_1tOlvxC1v_0PCwor8uB7eSGEm7av_1QnG1Dx_05Hn_0h4V_04DuwJfG_1kHhNemdPja_1rTTiz0JIoTdVPu4WAsWvYnDxmRJtTV9mQfHqqKY12o73T2OxgXFE9F1k_1IMarh7o_10DqlMR4YZl_1PMbb6Is7PcmJt5NpzcJdr_1xfMRGZkxfV834bkDYPeEL9



#ifndef SPL_OPER_INSTANCE_DATAFEED_PARSEROUTPUT_PARSEROUTPUT_H_
#define SPL_OPER_INSTANCE_DATAFEED_PARSEROUTPUT_PARSEROUTPUT_H_

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

#include "../../../type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.h"
#include "../../../type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.h"

#include <bitset>

#define MY_OPERATOR ParserOutput$OP
#define MY_BASE_OPERATOR ParserOutput_Base
#define MY_OPERATOR_SCOPE SPL::_Operator::DataFeed::ParserOutput

namespace SPL {
namespace _Operator {
namespace DataFeed {
namespace ParserOutput {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc IPort0Type;
    typedef SPL::BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    SPL::int32 lit$1;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
   MY_OPERATOR() {}
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
}; 

} // namespace DataFeed
} // namespace ParserOutput
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_DATAFEED_PARSEROUTPUT_PARSEROUTPUT_H_

