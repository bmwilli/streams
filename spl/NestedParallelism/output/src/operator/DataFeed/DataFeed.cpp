// eJylVF1vmzAUlV_1zK7yqD6Bu2Plo15JtUhq1kypKK9HudTLECVaMjbApS6L89zmGRiRq_0oJB4t7j63N9fY9ROfdKzTjTK9_0flkrLDPQBNk8fnHkeMq9e5RTd0oeqeIyWg_1Du7Wl9rYOX6PvD_0vFmvVY3wQpXb_0FyGETX_18LgJQ4nf36nab6c3F9Onm4TLz0DA6A00fRcg_0g58P0ObN0JcGcKx_1USTknhuE1Zza5KJvTV6MDuA3O05xhcNd_12nIX6NcSZ0j_0sVShdMLGAv_0r5AWijNTb8AGulHQ5q6LKG5lwSm27Tg2ZUKeMUOnYqltLUIZwvvm_19_01IkmkmhfP_11XRRMRWmpZ7ISjuu6lmI3NntrN5rueguq_1yZSCGppplLM2cJx4U9oS_1WIdj7JZBZPU2IWc5NpfJJ_1LkhG96SD04H8IHB4OpDZoKaVFxeHgTMJN7CrYqCmWb7PocdQlXHGNHR2_0Fe7v5E7htu6Ow4_0Kv_0TQ4u5TJaObXdr0ba37QGUyoyiuGBEoAXTKM4qxjlDRjaUZAqpnKOQKk1nz6QgnFMjwgx9I0BIQXHzE8BA5rLYS7fLxctAAUbgWB7gXcYY2M62fH7kM9DcHIz_1A5bnG7K


#include "./DataFeed.h"
using namespace SPL::_Operator::DataFeed;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator::DataFeed
#define MY_BASE_OPERATOR DataFeed_Base
#define MY_OPERATOR DataFeed$OP




   void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t index)
   {
        {
    while (SPL::boolean(!::SPL::Functions::Utility::isShutdown()))
        {
            state$t.get_connectionConfig() = lit$1.at(::SPL::Functions::Utility::getChannel());
            state$t.get_fname() = lit$2;
            state$t.get_lname() = lit$3;
            state$t.get_i() = state$c++;
            do { SPL::BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc temp = state$t; submit (temp, lit$4); } while(0);
            ::SPL::Functions::Utility::block(lit$5);
        }
}

   }

   void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady()
   {
        createThreads(1);
   }

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("DataFeed::DataFeed",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    state$t = SPL::BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc().clear();
    SPLAPPTRC(L_DEBUG, "Variable: state$t Value: " << state$t,SPL_OPER_DBG);
    state$c = lit$0;
    SPLAPPTRC(L_DEBUG, "Variable: state$c Value: " << state$c,SPL_OPER_DBG);
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
    opstate << state$t;
    opstate << state$c;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$t;
    opstate >> state$c;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$t;
    ckpt << state$c;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$t;
    ckpt >> state$c;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$t = SPL::BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc().clear();
    SPLAPPTRC(L_DEBUG, "Variable: state$t Value: " << state$t,SPL_OPER_DBG);
    state$c = lit$0;
    SPLAPPTRC(L_DEBUG, "Variable: state$c Value: " << state$c,SPL_OPER_DBG);
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return true;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}



