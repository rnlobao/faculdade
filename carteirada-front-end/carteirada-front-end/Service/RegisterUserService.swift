//
//  RegisterUserService.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 22/09/22.
//

import Foundation
import Alamofire

class RegisterUserService {
    func postUser(name: String, email: String, password: String, sucess: @escaping (User)-> Void,error: @escaping (Error)-> Void) {
            var parameter =  [String:Any]()
            parameter["name"] = name
            parameter["email"] = email
            parameter["password"] = password
            
            NetworkService.request(url: "", method: .post, params: parameter, obj: User.self) { result in
                sucess(result)
            } error: { e in
                error(e)
            }
        }
}
