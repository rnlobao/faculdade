//
//  NetworkService.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import Foundation
import Alamofire

class NetworkService {
    
    static private var alamoFireManager: Session? = {
        let configuration = URLSessionConfiguration.default
        configuration.requestCachePolicy = .reloadIgnoringCacheData
        let alamoFireManager = Alamofire.Session(configuration: configuration)
        return alamoFireManager
    }()
    
    static func request<T: Codable>(url: String,method: HTTPMethod , params: [String:Any]? = nil, obj: T.Type, sucess: @escaping (T)-> Void, error: @escaping (Error)-> Void) {
        alamoFireManager?.request(url, method: method, parameters: params, encoding: JSONEncoding.prettyPrinted).responseJSON { response in
            switch response.result {
            case .success:
                do {
                    let resultObj = try JSONDecoder().decode(obj.self, from: response.data ?? Data())
                    sucess(resultObj)
                } catch let decodeErr {
                    error(decodeErr)
                }
                return
            case .failure:
                error(response.error!)
                return
            }
        }
    }
}
