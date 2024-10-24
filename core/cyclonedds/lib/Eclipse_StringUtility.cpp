#include "../include/Eclipse_StringUtility.h"

std::string multiple_tap(int tap_size){
    std::string tmp = "";
    while(tap_size--)
        tmp += "\t";

    return tmp;
}

std::string find_content(std::string qos, std::string tag){
    std::string start_tag = "<" + tag + ">";
    std::string end_tag   = "</" + tag + ">";

    int st=0, en;
    st = qos.find(start_tag, st);
    st = qos.find(">", st); st++;
    en = qos.find(end_tag, st);

    std::string content = qos.substr(st, en - st);
    return content;
}






std::string convert_durability_qos_to_string(dds_durability_qospolicy_t durability, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<DurabilityQosPolicy_>" + "\n";
    tab += "\t";

    switch (durability.kind){
        case DDS_DURABILITY_VOLATILE:
            result += tab + "<kind>" + "VOLATILE_DURABILITY_QOS" + "</kind>" + "\n";
            break;
        case DDS_DURABILITY_TRANSIENT_LOCAL:
            result += tab + "<kind>" + "TRANSIENT_LOCAL_DURABILITY_QOS" + "</kind>" + "\n";
            break;
        case DDS_DURABILITY_TRANSIENT:
            result += tab + "<kind>" + "TRANSIENT_DURABILITY_QOS" + "</kind>" + "\n";
            break;
        case DDS_DURABILITY_PERSISTENT:
            result += tab + "<kind>" + "PERSISTENT_DURABILITY_QOS" + "</kind>" + "\n";
            break;
        default:
            break;
    }

    tab = multiple_tap(tab_size);
    result += tab + "</DurabilityQosPolicy_>" + "\n";   

    return result;
}

std::string convert_durability_service_qos_to_string(dds_durability_service_qospolicy_t service, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<DurabilityServiceQosPolicy_>" + "\n";
    tab += "\t";

    result += tab + "<service_cleanup_delay>" + std::to_string(service.service_cleanup_delay) + "</service_cleanup_delay>" + "\n";
    switch (service.history.kind){
        case DDS_HISTORY_KEEP_LAST:
            result += tab + "<history_kind>" + "KEEP_LAST_HISTORY_QOS" + "</history_kind>" + "\n";
            break;
        case DDS_HISTORY_KEEP_ALL:
            result += tab + "<history_kind>" + "KEEP_ALL_HISTORY_QOS" + "</history_kind>" + "\n";
            break;
        default:
            break;
    }
    result += tab + "<history_depth>" + std::to_string(service.history.depth) + "</history_depth>" + "\n";
    result += tab + "<max_samples>" + std::to_string(service.resource_limits.max_samples) + "</max_samples>" + "\n";
    result += tab + "<max_instances>" + std::to_string(service.resource_limits.max_instances) + "</max_instances>" + "\n";
    result += tab + "<max_samples_per_instance>" + std::to_string(service.resource_limits.max_samples_per_instance) + "</max_samples_per_instance>" + "\n";
    
    tab = multiple_tap(tab_size);
    result += tab + "</DurabilityServiceQosPolicy_>" + "\n";   

    return result;
}

std::string convert_deadline_qos_to_string(dds_deadline_qospolicy_t deadline, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<DeadlineQosPolicy_>" + "\n";
    tab += "\t";

    result += tab + "<period>" + std::to_string(deadline.deadline) + "</period>" + "\n";

    tab = multiple_tap(tab_size);
    result += tab + "</DeadlineQosPolicy_>" + "\n";  

    return result;
}

std::string convert_latency_budget_qos_to_string(dds_latency_budget_qospolicy_t latency, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<LatencyBudgetQosPolicy_>" + "\n";
    tab += "\t";

    result += tab + "<duration>" + std::to_string(latency.duration) + "</duration>" + "\n";
    
    tab = multiple_tap(tab_size);
    result += tab + "</LatencyBudgetQosPolicy_>" + "\n";  

    return result;
}

std::string convert_liveliness_qos_to_string(dds_liveliness_qospolicy_t liveliness, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<LivelinessQosPolicy_>" + "\n";
    tab += "\t";

    switch (liveliness.kind){
        case DDS_LIVELINESS_AUTOMATIC:
            result += tab + "<kind>" + "AUTOMATIC_LIVELINESS_QOS" + "</kind>" + "\n";
            break;
        case DDS_LIVELINESS_MANUAL_BY_PARTICIPANT:
            result += tab + "<kind>" + "MANUAL_BY_PARTICIPANT_LIVELINESS_QOS" + "</kind>" + "\n";
            break;
        case DDS_LIVELINESS_MANUAL_BY_TOPIC:
            result += tab + "<kind>" + "MANUAL_BY_TOPIC_LIVELINESS_QOS" + "</kind>" + "\n";
            break;
        default:
            break;
    }
    result += tab + "<lease_duration>" + std::to_string(liveliness.lease_duration) + "</lease_duration>" + "\n";
    
    tab = multiple_tap(tab_size);
    result += tab + "</LivelinessQosPolicy_>" + "\n";  

    return result;
}

std::string convert_reliability_qos_to_string(dds_reliability_qospolicy_t reliability, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<ReliabilityQosPolicy_>" + "\n";
    tab += "\t";

    switch (reliability.kind){
        case DDS_RELIABILITY_BEST_EFFORT:
            result += tab + "<kind>" + "BEST_EFFORT_RELIABILITY_QOS" + "</kind>" + "\n";
            break;
        case DDS_RELIABILITY_RELIABLE:
            result += tab + "<kind>" + "RELIABLE_RELIABILITY_QOS" + "</kind>" + "\n";
            break;
        default:
            break;
    }
    result += tab + "<max_blocking_time>" + std::to_string(reliability.max_blocking_time) + "</max_blocking_time>" + "\n";

    tab = multiple_tap(tab_size);
    result += tab + "</ReliabilityQosPolicy_>" + "\n";  

    return result;
}

std::string convert_destination_order_qos_to_string(dds_destination_order_qospolicy destination, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<DestinationOrderQosPolicy_>" + "\n";
    tab += "\t";

    switch (destination.kind){
        case DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP:
            result += tab + "<kind>" + "BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS" + "</kind>" + "\n";
            break;
        case DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP:
            result += tab + "<kind>" + "BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS" + "</kind>" + "\n";
            break;
        default:
            break;
    }

    tab = multiple_tap(tab_size);
    result += tab + "</DestinationOrderQosPolicy_>" + "\n";  

    return result;
}

std::string convert_history_qos_to_string(dds_history_qospolicy_t history, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<HistoryQosPolicy_>" + "\n";
    tab += "\t";

    switch (history.kind){
        case DDS_HISTORY_KEEP_LAST:
            result += tab + "<kind>" + "KEEP_LAST_HISTORY_QOS" + "</kind>" + "\n";
            break;
        case DDS_HISTORY_KEEP_ALL:
            result += tab + "<kind>" + "KEEP_ALL_HISTORY_QOS" + "</kind>" + "\n";
            break;
        default:
            break;
    }
    result += tab + "<depth>" + std::to_string(history.depth) + "</depth>" + "\n";

    tab = multiple_tap(tab_size);
    result += tab + "</HistoryQosPolicy_>" + "\n";  

    return result;
}

std::string convert_resource_limits_qos_to_string(dds_resource_limits_qospolicy_t limits, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<ResourceLimitsQosPolicy_>" + "\n";
    tab += "\t";

    result += tab + "<max_samples>" + std::to_string(limits.max_samples) + "</max_samples>" + "\n";
    result += tab + "<max_instances>" + std::to_string(limits.max_instances) + "</max_instances>" + "\n";
    result += tab + "<max_samples_per_instance>" + std::to_string(limits.max_samples_per_instance) + "</max_samples_per_instance>" + "\n";
    
    tab = multiple_tap(tab_size);
    result += tab + "</ResourceLimitsQosPolicy_>" + "\n";  

    return result;
}

std::string convert_transport_priority_qos_to_string(dds_transport_priority_qospolicy_t priority, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<TransportPriorityQosPolicy_>" + "\n";
    tab += "\t";

    result += tab + "<value>" + std::to_string(priority.value) + "</value>" + "\n";
     
    tab = multiple_tap(tab_size);
    result += tab + "</TransportPriorityQosPolicy_>" + "\n";  

    return result;
}

std::string convert_lifespan_qos_to_string(dds_lifespan_qospolicy_t lifespan, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<LifespanQosPolicy_>" + "\n";
    tab += "\t";
    
    result += tab + "<duration>" + std::to_string(lifespan.duration) + "</duration>" + "\n";
     
    tab = multiple_tap(tab_size);
    result += tab + "</LifespanQosPolicy_>" + "\n";  

    return result;
}

std::string convert_ownership_qos_to_string(dds_ownership_qospolicy_t owner, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<OwnershipQosPolicy_>" + "\n";
    tab += "\t";
    
    switch (owner.kind){
        case DDS_OWNERSHIP_SHARED:
            result += tab + "<kind>" + "SHARED_OWNERSHIP_QOS" + "</kind>" + "\n";
            break;
        case DDS_OWNERSHIP_EXCLUSIVE:
            result += tab + "<kind>" + "EXCLUSIVE_OWNERSHIP_QOS" + "</kind>" + "\n";
            break;
        default:
            break;
    }
     
    tab = multiple_tap(tab_size);
    result += tab + "</OwnershipQosPolicy_>" + "\n";  

    return result;
}

std::string convert_ownership_strength_qos_to_string(dds_ownership_strength_qospolicy_t strength, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<OwnershipStrengthQosPolicy_>" + "\n";
    tab += "\t";
    
    result += tab + "<value>" + std::to_string(strength.value) + "</value>" + "\n";
     
    tab = multiple_tap(tab_size);
    result += tab + "</OwnershipStrengthQosPolicy_>" + "\n";  

    return result;
}

std::string convert_writer_data_lifecycle_qos_to_string(dds_writer_data_lifecycle_qospolicy_t writer, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<WriterDataLifecycleQosPolicy_>" + "\n";
    tab += "\t";
    
    result += tab + "<autodispose_unregistered_instances>";
    if(writer.autodispose_unregistered_instances) result += TRUE;
    else                                          result += FALSE;
    result += "</autodispose_unregistered_instances>\n";

    tab = multiple_tap(tab_size);
    result += tab + "</WriterDataLifecycleQosPolicy_>" + "\n";  

    return result;
}

std::string convert_time_based_filter_qos_to_string(dds_time_based_filter_qospolicy_t time, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<TimeBasedFilterQosPolicy_>" + "\n";
    tab += "\t";
    
    result += tab + "<minimum_separation>" + std::to_string(time.minimum_separation) + "</minimum_separation>" + "\n";

    tab = multiple_tap(tab_size);
    result += tab + "</TimeBasedFilterQosPolicy_>" + "\n";  

    return result;
}

std::string convert_reader_data_lifecycle_qos_to_string(dds_reader_data_lifecycle_qospolicy_t reader, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<ReaderDataLifecycleQosPolicy_>" + "\n";
    tab += "\t";
    
    result += tab + "<autopurge_no_writer_samples_delay>" + std::to_string(reader.autopurge_nowriter_samples_delay) + "</autopurge_no_writer_samples_delay>" + "\n";
    result += tab + "<autopurge_disposed_samples_delay>" + std::to_string(reader.autopurge_disposed_samples_delay) + "</autopurge_disposed_samples_delay>" + "\n";
    
    tab = multiple_tap(tab_size);
    result += tab + "</ReaderDataLifecycleQosPolicy_>" + "\n";  

    return result;
}

std::string convert_entity_factory_qos_to_string(dds_entity_factory_qospolicy_t entity, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<EntityFactoryQosPolicy_>" + "\n";
    tab += "\t";
    
    result += tab + "<autoenable_created_entities>" + TRUE + "</autoenable_created_entities>" + '\n';
    
    tab = multiple_tap(tab_size);
    result += tab + "</EntityFactoryQosPolicy_>" + "\n";  

    return result;
}

std::string convert_presentation_qos_to_string(dds_presentation_qospolicy_t presentation, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<PresentationQosPolicy_>" + "\n";
    tab += "\t";
    
    switch (presentation.access_scope){
        case DDS_PRESENTATION_INSTANCE:
            result += tab + "<access_scope>" + "INSTANCE_PRESENTATION_QOS" + "</access_scope>" + "\n";
            break;
        case DDS_PRESENTATION_TOPIC:
            result += tab + "<access_scope>" + "TOPIC_PRESENTATION_QOS" + "</access_scope>" + "\n";
            break;
        case DDS_PRESENTATION_GROUP:
            result += tab + "<access_scope>" + "GROUP_PRESENTATION_QOS" + "</access_scope>" + "\n";
            break;
        default:
            break;
    }
    if(presentation.coherent_access)
        result += tab + "<coherent_access>" + TRUE + "</coherent_access>" + "\n";
    else result += tab + "<coherent_access>" + FALSE + "</coherent_access>" + "\n";
    
    if(presentation.ordered_access)
        result += tab + "<ordered_access>" + TRUE + "</ordered_access>" + "\n";
    else result += tab + "<ordered_access>" + FALSE + "</ordered_access>" + "\n";
    
    tab = multiple_tap(tab_size);
    result += tab + "</PresentationQosPolicy_>" + "\n";  

    return result;
}






dds_durability_qospolicy_t convert_string_to_durability_qos(std::string qos){
    dds_durability_qospolicy_t durability;
    int st = 0, en;

    st = qos.find("<kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</kind>", st);

    std::string durability_kind = qos.substr(st, en - st);
    if(durability_kind == "VOLATILE_DURABILITY_QOS")
        durability.kind = DDS_DURABILITY_VOLATILE;
    else if(durability_kind == "TRANSIENT_LOCAL_DURABILITY_QOS")
        durability.kind = DDS_DURABILITY_TRANSIENT_LOCAL;
    else if(durability_kind == "TRANSIENT_DURABILITY_QOS")
        durability.kind = DDS_DURABILITY_TRANSIENT;
    else if(durability_kind == "PERSISTENT_DURABILITY_QOS")
        durability.kind = DDS_DURABILITY_PERSISTENT;

    return durability;
}

dds_durability_service_qospolicy_t convert_string_to_durability_service_qos(std::string qos){
    dds_durability_service_qospolicy_t service;
    int st = 0, en;

    st = qos.find("<service_cleanup_delay>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</service_cleanup_delay>", st);
    long durability_service_delay = stol(qos.substr(st, en - st));
    service.service_cleanup_delay = durability_service_delay;
    st = en;

    st = qos.find("<history_kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</history_kind>", st);

    std::string durability_service_history_kind = qos.substr(st, en - st);
    if(durability_service_history_kind == "KEEP_LAST_HISTORY_QOS")
        service.history.kind = DDS_HISTORY_KEEP_LAST;
    else if(durability_service_history_kind == "KEEP_ALL_HISTORY_QOS")
        service.history.kind = DDS_HISTORY_KEEP_ALL;
    st = en;

    st = qos.find("<history_depth>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</history_depth>", st);
    service.history.depth = stol(qos.substr(st, en - st));
    st = en;

    st = qos.find("<max_samples>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_samples>", st);
    service.resource_limits.max_samples = stol(qos.substr(st, en - st));
    st = en;

    st = qos.find("<max_instances>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_instances>", st);
    service.resource_limits.max_instances = stol(qos.substr(st, en - st));
    st = en;

    st = qos.find("<max_samples_per_instance>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_samples_per_instance>", st);
    service.resource_limits.max_samples_per_instance = stol(qos.substr(st, en - st));

    return service;
}

dds_deadline_qospolicy_t convert_string_to_deadline_qos(std::string qos){
    dds_deadline_qospolicy_t deadline;
    int st = 0, en;

    st = qos.find("<period>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</period>", st);
    long deadline_period = stol(qos.substr(st, en - st));
    deadline.deadline = deadline_period;

    return deadline;
}

dds_latency_budget_qospolicy_t convert_string_to_latency_budget_qos(std::string qos){
    dds_latency_budget_qospolicy_t latency;
    int st = 0, en;

    st = qos.find("<duration>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</duration>", st);
    long latency_duration = stol(qos.substr(st, en - st));
    latency.duration = latency_duration;

    return latency;
}

dds_liveliness_qospolicy_t convert_string_to_liveliness_qos(std::string qos){
    dds_liveliness_qospolicy_t liveliness;
    int st = 0, en;

    st = qos.find("<kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</kind>", st);
    std::string liveliness_kind = qos.substr(st, en - st);
    if(liveliness_kind == "AUTOMATIC_LIVELINESS_QOS")
        liveliness.kind = DDS_LIVELINESS_AUTOMATIC;
    else if(liveliness_kind == "MANUAL_BY_PARTICIPANT_LIVELINESS_QOS")
        liveliness.kind = DDS_LIVELINESS_MANUAL_BY_PARTICIPANT;
    else if(liveliness_kind == "MANUAL_BY_TOPIC_LIVELINESS_QOS")
        liveliness.kind = DDS_LIVELINESS_MANUAL_BY_TOPIC;
    st = en;

    st = qos.find("<lease_duration>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</lease_duration>", st);
    long liveliness_duration = stol(qos.substr(st, en - st));

    liveliness.lease_duration = liveliness_duration;

    return liveliness;
}

dds_reliability_qospolicy_t convert_string_to_reliability_qos(std::string qos){
    dds_reliability_qospolicy_t reliability;
    int st = 0, en;

    st = qos.find("<kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</kind>", st);
    std::string reliability_kind = qos.substr(st, en - st);
    if(reliability_kind == "BEST_EFFORT_RELIABILITY_QOS")
        reliability.kind = DDS_RELIABILITY_BEST_EFFORT;
    else if(reliability_kind == "RELIABLE_RELIABILITY_QOS")
        reliability.kind = DDS_RELIABILITY_RELIABLE;
    st = en;

    st = qos.find("<max_blocking_time>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_blocking_time>", st);
    long reliability_max_blocking_time = stol(qos.substr(st, en - st));
    reliability.max_blocking_time = reliability_max_blocking_time;

    return reliability;
}

dds_destination_order_qospolicy convert_string_to_destination_qos(std::string qos){
    dds_destination_order_qospolicy order;
    int st = 0, en;

    st = qos.find("<kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</kind>", st);
    std::string destination_order_kind = qos.substr(st, en - st);
    if(destination_order_kind == "BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS")
        order.kind = DDS_DESTINATIONORDER_BY_RECEPTION_TIMESTAMP;
    else if(destination_order_kind == "BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS")
        order.kind = DDS_DESTINATIONORDER_BY_SOURCE_TIMESTAMP;
    
    return order;
}

dds_history_qospolicy_t convert_string_to_history_qos(std::string qos){
    dds_history_qospolicy_t history;
    int st = 0, en;

    st = qos.find("<kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</kind>", st);
    std::string history_kind = qos.substr(st, en - st);
    if(history_kind == "KEEP_LAST_HISTORY_QOS")
        history.kind = DDS_HISTORY_KEEP_LAST;
    else if(history_kind == "KEEP_ALL_HISTORY_QOS")
        history.kind = DDS_HISTORY_KEEP_ALL;
    st = en;

    st = qos.find("<depth>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</depth>", st);
    history.depth = stol(qos.substr(st, en - st));

    return history;
}

dds_resource_limits_qospolicy_t convert_string_to_resource_limits_qos(std::string qos){
    dds_resource_limits_qospolicy_t limits;
    int st = 0, en;

    st = qos.find("<max_samples>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_samples>", st);
    limits.max_samples = stol(qos.substr(st, en - st));
    st = en;

    st = qos.find("<max_instances>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_instances>", st);
    limits.max_instances = stol(qos.substr(st, en - st));
    st = en;

    st = qos.find("<max_samples_per_instance>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</max_samples_per_instance>", st);
    limits.max_samples_per_instance = stol(qos.substr(st, en - st));
    
    return limits;
}

dds_transport_priority_qospolicy_t convert_string_to_transport_priority_qos(std::string qos){
    dds_transport_priority_qospolicy_t priority;
    int st = 0, en;

    st = qos.find("<value>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</value>", st);
    priority.value = stol(qos.substr(st, en - st));

    return priority;  
}

dds_lifespan_qospolicy_t convert_string_to_lifespan_qos(std::string qos){
    dds_lifespan_qospolicy_t lifespan;
    int st = 0, en;

    st = qos.find("<duration>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</duration>", st);
    long lifespan_duration = stol(qos.substr(st, en - st));
    lifespan.duration = lifespan_duration;
    
    return lifespan;
}

dds_ownership_qospolicy_t convert_string_to_ownership_qos(std::string qos){
    dds_ownership_qospolicy_t owner;
    int st = 0, en;

    st = qos.find("<kind>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</kind>", st);
    std::string ownership_kind = qos.substr(st, en - st);
    if(ownership_kind == "SHARED_OWNERSHIP_QOS")
        owner.kind = DDS_OWNERSHIP_SHARED;
    else if(ownership_kind == "EXCLUSIVE_OWNERSHIP_QOS")
        owner.kind = DDS_OWNERSHIP_EXCLUSIVE;
    
    return owner;
}

dds_ownership_strength_qospolicy_t convert_string_to_ownership_strength_qos(std::string qos){
    dds_ownership_strength_qospolicy_t strength;
    int st = 0, en;

    st = qos.find("<value>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</value>", st);
    strength.value = stol(qos.substr(st, en - st));
    
    return strength;
}

dds_writer_data_lifecycle_qospolicy_t convert_string_to_writer_data_lifecycle_qos(std::string qos){
    dds_writer_data_lifecycle_qospolicy_t lifecycle;
    int st = 0, en;

    st = qos.find("<autodispose_unregistered_instances>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</autodispose_unregistered_instances>", st);
    std::string dw_writer_data_lifecycle_autodispose_unregistered_instances = qos.substr(st, en - st);
    if(dw_writer_data_lifecycle_autodispose_unregistered_instances == TRUE)
        lifecycle.autodispose_unregistered_instances = true;
    else lifecycle.autodispose_unregistered_instances = false;

    return lifecycle;
}

dds_time_based_filter_qospolicy_t convert_string_to_time_based_filter_qos(std::string qos){
    dds_time_based_filter_qospolicy_t filter;
    int st = 0, en;

    st = qos.find("<minimum_separation>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</minimum_separation>", st);
    long time_based_filter_minimum_separation = stol(qos.substr(st, en - st));
    filter.minimum_separation = time_based_filter_minimum_separation;
    
    return filter;
}

dds_reader_data_lifecycle_qospolicy_t convert_string_to_reader_data_lifecycle_qos(std::string qos){
    dds_reader_data_lifecycle_qospolicy_t lifecycle;
    int st = 0, en;

    st = qos.find("<autopurge_no_writer_samples_delay>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</autopurge_no_writer_samples_delay>", st);
    long reader_no_writer = stol(qos.substr(st, en - st));
    lifecycle.autopurge_nowriter_samples_delay = reader_no_writer;
    st = en;

    st = qos.find("<autopurge_disposed_samples_delay>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</autopurge_disposed_samples_delay>", st);
    long reader_disposed = stol(qos.substr(st, en - st));
    lifecycle.autopurge_disposed_samples_delay = reader_disposed;
    
    return lifecycle;
}

dds_entity_factory_qospolicy_t convert_string_to_entity_factory_qos(std::string qos){
    dds_entity_factory_qospolicy_t entity;
    int st = 0, en;

    st = qos.find("<autoenable_created_entities>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</autoenable_created_entities>", st);

    std::string pub_entity_autoenable_created_entities = qos.substr(st, en - st);
    if(pub_entity_autoenable_created_entities == TRUE)
        entity.autoenable_created_entities = true;
    else entity.autoenable_created_entities = false;
    
    return entity;
}

dds_presentation_qospolicy_t convert_string_to_presentation_qos(std::string qos){
    dds_presentation_qospolicy_t presentation;
    int st = 0, en;

    st = qos.find("<access_scope>", 0);
    st = qos.find(">", st); st++;
    en = qos.find("</access_scope>", st);

    std::string presentation_access_scope = qos.substr(st, en - st);
    if(presentation_access_scope == "INSTANCE_PRESENTATION_QOS")
        presentation.access_scope = DDS_PRESENTATION_INSTANCE;
    else if(presentation_access_scope == "TOPIC_PRESENTATION_QOS")
        presentation.access_scope = DDS_PRESENTATION_TOPIC;
    else if(presentation_access_scope == "GROUP_PRESENTATION_QOS")
        presentation.access_scope = DDS_PRESENTATION_GROUP;
    st = en;

    st = qos.find("<coherent_access>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</coherent_access>", st);
    std::string pub_presentation_coherent_access = qos.substr(st, en - st);
    if(pub_presentation_coherent_access == TRUE)
        presentation.coherent_access = true;
    else presentation.coherent_access = false;
    st = en;

    st = qos.find("<ordered_access>", st);
    st = qos.find(">", st); st++;
    en = qos.find("</ordered_access>", st);
    std::string pub_presentation_ordered_access = qos.substr(st, en - st);
    if(pub_presentation_ordered_access == TRUE)
        presentation.ordered_access = true;
    else presentation.ordered_access = false;
    
    return presentation;
}






dds_qos_t* convert_string_to_topic_qos(std::string qos_str){
    dds_qos_t* qos = dds_create_qos();

    std::string durability_str   = find_content(qos_str, "DurabilityQosPolicy_");
    std::string service_str      = find_content(qos_str, "DurabilityServiceQosPolicy_");
    std::string deadline_str     = find_content(qos_str, "DeadlineQosPolicy_");
    std::string latency_str      = find_content(qos_str, "LatencyBudgetQosPolicy_");
    std::string liveliness_str   = find_content(qos_str, "LivelinessQosPolicy_");
    std::string reliability_str  = find_content(qos_str, "ReliabilityQosPolicy_");
    std::string destination_str  = find_content(qos_str, "DestinationOrderQosPolicy_");
    std::string history_str      = find_content(qos_str, "HistoryQosPolicy_");
    std::string resource_str     = find_content(qos_str, "ResourceLimitsQosPolicy_");
    std::string transport_str    = find_content(qos_str, "TransportPriorityQosPolicy_");
    std::string lifespan_str     = find_content(qos_str, "LifespanQosPolicy_");
    std::string owner_str        = find_content(qos_str, "OwnershipQosPolicy_");

    dds_durability_qospolicy_t durability           = convert_string_to_durability_qos(durability_str);
    dds_durability_service_qospolicy_t service      = convert_string_to_durability_service_qos(service_str);
    dds_deadline_qospolicy_t deadline               = convert_string_to_deadline_qos(deadline_str);
    dds_latency_budget_qospolicy_t latency          = convert_string_to_latency_budget_qos(latency_str);
    dds_liveliness_qospolicy_t liveliness           = convert_string_to_liveliness_qos(liveliness_str);
    dds_reliability_qospolicy_t reliability         = convert_string_to_reliability_qos(reliability_str);
    dds_destination_order_qospolicy_t destination   = convert_string_to_destination_qos(destination_str);
    dds_history_qospolicy_t history                 = convert_string_to_history_qos(history_str);
    dds_resource_limits_qospolicy_t resource        = convert_string_to_resource_limits_qos(resource_str);
    dds_transport_priority_qospolicy_t transport    = convert_string_to_transport_priority_qos(transport_str);
    dds_lifespan_qospolicy_t lifespan               = convert_string_to_lifespan_qos(lifespan_str);
    dds_ownership_qospolicy_t owner                 = convert_string_to_ownership_qos(owner_str);

    dds_qset_durability(qos, durability.kind);
    dds_qset_durability_service(qos, 
                                service.service_cleanup_delay, 
                                service.history.kind, 
                                service.history.depth, 
                                service.resource_limits.max_samples, 
                                service.resource_limits.max_instances, 
                                service.resource_limits.max_samples_per_instance);
    dds_qset_deadline(qos, deadline.deadline);
    dds_qset_latency_budget(qos, latency.duration);
    dds_qset_liveliness(qos, liveliness.kind, liveliness.lease_duration);
    dds_qset_reliability(qos, reliability.kind, reliability.max_blocking_time);
    dds_qset_destination_order(qos, destination.kind);
    dds_qset_history(qos, history.kind, history.depth);
    dds_qset_resource_limits(qos, resource.max_samples, resource.max_instances, resource.max_samples_per_instance);
    dds_qset_transport_priority(qos, transport.value);
    dds_qset_lifespan(qos, lifespan.duration);
    dds_qset_ownership(qos, owner.kind);

    return qos;
}

dds_qos_t* convert_string_to_participant_qos(std::string qos_str){
    dds_qos_t* qos = dds_create_qos();

    std::string entity_str       = find_content(qos_str, "EntityFactoryQosPolicy_");

    dds_entity_factory_qospolicy_t entity = convert_string_to_entity_factory_qos(entity_str);


    // dds_qset_entity_factory(qos, entity.autoenable_created_entities);

    return qos;
}

dds_qos_t* convert_string_to_publisher_qos(std::string qos_str){
    dds_qos_t* qos = dds_create_qos();

    std::string presentation_str = find_content(qos_str, "PresentationQosPolicy_");
    std::string entity_str       = find_content(qos_str, "EntityFactoryQosPolicy_");

    dds_presentation_qospolicy_t presentation   = convert_string_to_presentation_qos(presentation_str);
    dds_entity_factory_qospolicy_t entity       = convert_string_to_entity_factory_qos(entity_str);

    dds_qset_presentation(qos, presentation.access_scope, presentation.coherent_access, presentation.ordered_access);

    // dds_qset_entity_factory(qos, entity.autoenable_created_entities);

    return qos;
}

dds_qos_t* convert_string_to_subscriber_qos(std::string qos_str){
    dds_qos_t* qos = dds_create_qos();

    std::string presentation_str = find_content(qos_str, "PresentationQosPolicy_");
    std::string entity_str       = find_content(qos_str, "EntityFactoryQosPolicy_");

    dds_presentation_qospolicy_t presentation   = convert_string_to_presentation_qos(presentation_str);
    dds_entity_factory_qospolicy_t entity       = convert_string_to_entity_factory_qos(entity_str);

    dds_qset_presentation(qos, presentation.access_scope, presentation.coherent_access, presentation.ordered_access);

    // dds_qset_entity_factory(qos, entity.autoenable_created_entities);
    
    return qos;
}

dds_qos_t* convert_string_to_datawriter_qos(std::string qos_str){
    dds_qos_t* qos = dds_create_qos();

    std::string durability_str   = find_content(qos_str, "DurabilityQosPolicy_");
    std::string service_str      = find_content(qos_str, "DurabilityServiceQosPolicy_");
    std::string deadline_str     = find_content(qos_str, "DeadlineQosPolicy_");
    std::string latency_str      = find_content(qos_str, "LatencyBudgetQosPolicy_");
    std::string liveliness_str   = find_content(qos_str, "LivelinessQosPolicy_");
    std::string reliability_str  = find_content(qos_str, "ReliabilityQosPolicy_");
    std::string destination_str  = find_content(qos_str, "DestinationOrderQosPolicy_");
    std::string history_str      = find_content(qos_str, "HistoryQosPolicy_");
    std::string resource_str     = find_content(qos_str, "ResourceLimitsQosPolicy_");
    std::string transport_str    = find_content(qos_str, "TransportPriorityQosPolicy_");
    std::string lifespan_str     = find_content(qos_str, "LifespanQosPolicy_");
    std::string owner_str        = find_content(qos_str, "OwnershipQosPolicy_");
    std::string strength_str     = find_content(qos_str, "OwnershipStrengthQosPolicy_");
    std::string lifecyle_str     = find_content(qos_str, "WriterDataLifecycleQosPolicy_");

    dds_durability_qospolicy_t durability           = convert_string_to_durability_qos(durability_str);
    dds_durability_service_qospolicy_t service      = convert_string_to_durability_service_qos(service_str);
    dds_deadline_qospolicy_t deadline               = convert_string_to_deadline_qos(deadline_str);
    dds_latency_budget_qospolicy_t latency          = convert_string_to_latency_budget_qos(latency_str);
    dds_liveliness_qospolicy_t liveliness           = convert_string_to_liveliness_qos(liveliness_str);
    dds_reliability_qospolicy_t reliability         = convert_string_to_reliability_qos(reliability_str);
    dds_destination_order_qospolicy_t destination   = convert_string_to_destination_qos(destination_str);
    dds_history_qospolicy_t history                 = convert_string_to_history_qos(history_str);
    dds_resource_limits_qospolicy_t resource        = convert_string_to_resource_limits_qos(resource_str);
    dds_transport_priority_qospolicy_t transport    = convert_string_to_transport_priority_qos(transport_str);
    dds_lifespan_qospolicy_t lifespan               = convert_string_to_lifespan_qos(lifespan_str);
    dds_ownership_qospolicy_t owner                 = convert_string_to_ownership_qos(owner_str);
    dds_ownership_strength_qospolicy_t strength     = convert_string_to_ownership_strength_qos(strength_str);
    dds_writer_data_lifecycle_qospolicy_t lifecycle = convert_string_to_writer_data_lifecycle_qos(lifecyle_str);

    dds_qset_durability(qos, durability.kind);
    dds_qset_durability_service(qos, 
                                service.service_cleanup_delay, 
                                service.history.kind, 
                                service.history.depth, 
                                service.resource_limits.max_samples, 
                                service.resource_limits.max_instances, 
                                service.resource_limits.max_samples_per_instance);
    dds_qset_deadline(qos, deadline.deadline);
    dds_qset_latency_budget(qos, latency.duration);
    dds_qset_liveliness(qos, liveliness.kind, liveliness.lease_duration);
    dds_qset_reliability(qos, reliability.kind, reliability.max_blocking_time);
    dds_qset_destination_order(qos, destination.kind);
    dds_qset_history(qos, history.kind, history.depth);
    dds_qset_resource_limits(qos, resource.max_samples, resource.max_instances, resource.max_samples_per_instance);
    dds_qset_transport_priority(qos, transport.value);
    dds_qset_lifespan(qos, lifespan.duration);
    dds_qset_ownership(qos, owner.kind);
    dds_qset_ownership_strength(qos, strength.value);
    dds_qset_writer_data_lifecycle(qos, lifecycle.autodispose_unregistered_instances);

    return qos;
}

dds_qos_t* convert_string_to_datareader_qos(std::string qos_str){
    dds_qos_t* qos = dds_create_qos();

    std::string durability_str   = find_content(qos_str, "DurabilityQosPolicy_");
    std::string deadline_str     = find_content(qos_str, "DeadlineQosPolicy_");
    std::string latency_str      = find_content(qos_str, "LatencyBudgetQosPolicy_");
    std::string liveliness_str   = find_content(qos_str, "LivelinessQosPolicy_");
    std::string reliability_str  = find_content(qos_str, "ReliabilityQosPolicy_");
    std::string destination_str  = find_content(qos_str, "DestinationOrderQosPolicy_");
    std::string history_str      = find_content(qos_str, "HistoryQosPolicy_");
    std::string resource_str     = find_content(qos_str, "ResourceLimitsQosPolicy_");
    std::string owner_str        = find_content(qos_str, "OwnershipQosPolicy_");
    std::string filter_str       = find_content(qos_str, "TimeBasedFilterQosPolicy_");
    std::string lifecycle_str    = find_content(qos_str, "ReaderDataLifecycleQosPolicy_");

    dds_durability_qospolicy_t durability           = convert_string_to_durability_qos(durability_str);
    dds_deadline_qospolicy_t deadline               = convert_string_to_deadline_qos(deadline_str);
    dds_latency_budget_qospolicy_t latency          = convert_string_to_latency_budget_qos(latency_str);
    dds_liveliness_qospolicy_t liveliness           = convert_string_to_liveliness_qos(liveliness_str);
    dds_reliability_qospolicy_t reliability         = convert_string_to_reliability_qos(reliability_str);
    dds_destination_order_qospolicy_t destination   = convert_string_to_destination_qos(destination_str);
    dds_history_qospolicy_t history                 = convert_string_to_history_qos(history_str);
    dds_resource_limits_qospolicy_t resource        = convert_string_to_resource_limits_qos(resource_str);
    dds_ownership_qospolicy_t owner                 = convert_string_to_ownership_qos(owner_str);
    dds_time_based_filter_qospolicy_t filter        = convert_string_to_time_based_filter_qos(filter_str);
    dds_reader_data_lifecycle_qospolicy_t lifecycle = convert_string_to_reader_data_lifecycle_qos(lifecycle_str);

    dds_qset_durability(qos, durability.kind);
    dds_qset_deadline(qos, deadline.deadline);
    dds_qset_latency_budget(qos, latency.duration);
    dds_qset_liveliness(qos, liveliness.kind, liveliness.lease_duration);
    dds_qset_reliability(qos, reliability.kind, reliability.max_blocking_time);
    dds_qset_destination_order(qos, destination.kind);
    dds_qset_history(qos, history.kind, history.depth);
    dds_qset_resource_limits(qos, resource.max_samples, resource.max_instances, resource.max_samples_per_instance);
    dds_qset_ownership(qos, owner.kind);
    dds_qset_time_based_filter(qos, filter.minimum_separation);
    dds_qset_reader_data_lifecycle(qos, lifecycle.autopurge_nowriter_samples_delay, lifecycle.autopurge_disposed_samples_delay);

    return qos;
}






std::string convert_topic_qos_to_string(dds_qos_t* qos, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<qos>" + "\n";
    tab_size++;

    result += convert_durability_qos_to_string         (qos->durability, tab_size);
    result += convert_durability_service_qos_to_string (qos->durability_service, tab_size);
    result += convert_deadline_qos_to_string           (qos->deadline, tab_size);
    result += convert_latency_budget_qos_to_string     (qos->latency_budget, tab_size);
    result += convert_liveliness_qos_to_string         (qos->liveliness, tab_size);
    result += convert_reliability_qos_to_string        (qos->reliability, tab_size);
    result += convert_destination_order_qos_to_string  (qos->destination_order, tab_size);
    result += convert_history_qos_to_string            (qos->history, tab_size);
    result += convert_resource_limits_qos_to_string    (qos->resource_limits, tab_size);
    result += convert_transport_priority_qos_to_string (qos->transport_priority, tab_size);
    result += convert_lifespan_qos_to_string           (qos->lifespan, tab_size);
    result += convert_ownership_qos_to_string          (qos->ownership, tab_size);

    tab_size--;
    tab = multiple_tap(tab_size);
    result += tab + "</qos>" + "\n";

    return result;
}

std::string convert_participant_qos_to_string(dds_qos_t* qos, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<qos>" + "\n";
    tab_size++;

    result += convert_entity_factory_qos_to_string(qos->entity_factory, tab_size);

    tab_size--;
    tab = multiple_tap(tab_size);
    result += tab + "</qos>" + "\n";

    return result;
}

std::string convert_publisher_qos_to_string(dds_qos_t* qos, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<qos>" + "\n";
    tab_size++;

    result += convert_presentation_qos_to_string   (qos->presentation, tab_size);
    result += convert_entity_factory_qos_to_string (qos->entity_factory, tab_size);

    tab_size--;
    tab = multiple_tap(tab_size);
    result += tab + "</qos>" + "\n";

    return result;
}

std::string convert_subscriber_qos_to_string(dds_qos_t* qos, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<qos>" + "\n";
    tab_size++;

    result += convert_presentation_qos_to_string   (qos->presentation, tab_size);
    result += convert_entity_factory_qos_to_string (qos->entity_factory, tab_size);

    tab_size--;
    tab = multiple_tap(tab_size);
    result += tab + "</qos>" + "\n";

    return result;

}

std::string convert_datawriter_qos_to_string(dds_qos_t* qos, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<qos>" + "\n";
    tab_size++;

    result += convert_durability_qos_to_string             (qos->durability, tab_size);
    result += convert_durability_service_qos_to_string     (qos->durability_service, tab_size);
    result += convert_deadline_qos_to_string               (qos->deadline, tab_size);
    result += convert_latency_budget_qos_to_string         (qos->latency_budget, tab_size);
    result += convert_liveliness_qos_to_string             (qos->liveliness, tab_size);
    result += convert_reliability_qos_to_string            (qos->reliability, tab_size);
    result += convert_destination_order_qos_to_string      (qos->destination_order, tab_size);
    result += convert_history_qos_to_string                (qos->history, tab_size);
    result += convert_resource_limits_qos_to_string        (qos->resource_limits, tab_size);
    result += convert_transport_priority_qos_to_string     (qos->transport_priority, tab_size);
    result += convert_lifespan_qos_to_string               (qos->lifespan, tab_size);
    result += convert_ownership_qos_to_string              (qos->ownership, tab_size);
    result += convert_ownership_strength_qos_to_string     (qos->ownership_strength, tab_size);
    result += convert_writer_data_lifecycle_qos_to_string  (qos->writer_data_lifecycle, tab_size);

    tab_size--;
    tab = multiple_tap(tab_size);
    result += tab + "</qos>" + "\n";

    return result;
}

std::string convert_datareader_qos_to_string(dds_qos_t* qos, int tab_size){
    std::string result = "";

    std::string tab = multiple_tap(tab_size);

    result += tab + "<qos>" + "\n";
    tab_size++;

    result += convert_durability_qos_to_string             (qos->durability, tab_size);
    result += convert_deadline_qos_to_string               (qos->deadline, tab_size);
    result += convert_latency_budget_qos_to_string         (qos->latency_budget, tab_size);
    result += convert_liveliness_qos_to_string             (qos->liveliness, tab_size);
    result += convert_reliability_qos_to_string            (qos->reliability, tab_size);
    result += convert_destination_order_qos_to_string      (qos->destination_order, tab_size);
    result += convert_history_qos_to_string                (qos->history, tab_size);
    result += convert_resource_limits_qos_to_string        (qos->resource_limits, tab_size);
    result += convert_ownership_qos_to_string              (qos->ownership, tab_size);
    result += convert_time_based_filter_qos_to_string      (qos->time_based_filter, tab_size);
    result += convert_reader_data_lifecycle_qos_to_string  (qos->reader_data_lifecycle, tab_size);

    tab_size--;
    tab = multiple_tap(tab_size);
    result += tab + "</qos>" + "\n";

    return result;
}